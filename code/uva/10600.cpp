/*
  Kruskal's
  No neg cycle
  Undirected only
  Multiple edges valid
*/
#include<bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
 
const int N = 100000 , M = 1000000 ,lgN=20;
vector<int>U(M+1),V(M+1),W(M+1);
vector<int>used(M+1);
int n,m;
 
////////////////////  Kruskal's MST  ////////////////////////////
vector<int>par(N+1);
int root(int u){return par[u]<0?u:par[u]=root(par[u]);}
void merge(int u,int v)
{
	if( (u=root(u)) == (v=root(v)) )return ;
	if( par[u] > par[v] )swap(u,v);
	par[u]+=par[v];
	par[v]=u;
}
 
bool edgescmp(const int a , const int b)
{
	return W[a] < W[b];
}
int kruskal(int s=1 )
{
	/////////// Multiple test ///////////
	fill(used.begin(),used.begin()+m+1,0);
	fill(par.begin(),par.begin()+n+1,-1);
	/////////////////////////////////////
	
	vector<int>edges(m+1);
	for(int i=1;i<=m;i++)
	edges[i]=i;
	
	sort(edges.begin()+1,edges.end(),edgescmp);
	
	int cost=0;
	for(int i=1;i<=m;i++)
	{
		int id = edges[i];
		if( root(U[id]) != root(V[id]) )
		{
			merge(U[id],V[id]);
			used[id]=1;
			cost+=W[id];
		}
	}
	return cost;
}


/////////////////////  Binary Lifting ///////////////////////////
vector<vector<pair<int,int>>>G;
vector<int> tin;
vector<int> tout;
vector<vector<int>>up;
vector<vector<int>>mxw;
int t;

void dfs(int u,int p,int w)
{
	tin[u]=++t;
	up[u][0]=p;
	mxw[u][0]=w;
	for(int i=1;i<=lgN;i++)
	{
		up[u][i]=up[ up[u][i-1] ][i-1];
		mxw[u][i]=max(mxw[ up[u][i-1] ][i-1],mxw[u][i-1]);
	}
	for(auto it:G[u])
	{
		int v=it.first;
		int i=it.second;
		if( v!= p)
		{
			dfs(v,u,W[i]);
		}
	}
	tout[u]=++t;
}

int isAncestor(int u,int v)
{
	return tin[u]<=tin[v] && tout[v]<=tout[u];
}

int LCA(int u,int v)
{
	if( isAncestor(u,v) )return u;
	if( isAncestor(v,u) )return v;
	
	for(int i=lgN;i>=0;i--)
	if( up[u][i] && !isAncestor(up[u][i],v))
	u=up[u][i];
	
	return up[u][0];
}

int MaxWeightQuery(int u,int v)
{
	
	int l = LCA(u,v);
	int w = 0;
	if( u!=l )
	{
		for(int i=lgN;i>=0;i--)
	    if( up[u][i] && !isAncestor(up[u][i],l))
	    {
			w=max(w,mxw[u][i]);
			u=up[u][i];
		}
		w=max(w,mxw[u][0]);
	}
	if( v!=l )
	{
		for(int i=lgN;i>=0;i--)
	    if( up[v][i] && !isAncestor(up[v][i],l))
	    {
			w=max(w,mxw[v][i]);
			v=up[v][i];
		}
		w=max(w,mxw[v][0]);
	}
	return w;
}
/////////////////////////////////////////////////////////


int32_t main()
{
	IOS	
	int q;cin>>q;
	while(q--)
	{
	    cin>>n>>m;
	    for(int i=1;i<=m;i++)
	    cin>>U[i]>>V[i]>>W[i];
	    int ans1 = kruskal();
	    
	    //////////////////////// Multiple query ///////////////////
	    t=0;
	    G=vector<vector<pair<int,int>>>(n+1);
        tin=vector<int> (n+1);
        tout=vector<int> (n+1);
        up=vector<vector<int>>(n+1,vector<int>(lgN+1));
        mxw=vector<vector<int>>(n+1,vector<int>(lgN+1));
        
	    for(int i=1;i<=m;i++)
	    {
			if(used[i])
			{
				G[U[i]].push_back({V[i],i});
				G[V[i]].push_back({U[i],i});
			}
		}
		
		dfs(1,0,0);
		
		int ans2 = 1e18;
		for(int i=1;i<=m;i++)
		{
			if(!used[i])
			{
				int w = MaxWeightQuery(U[i],V[i]);
				ans2=min(ans2,ans1+W[i]-w);
			}
		}
		cout << ans1 <<" "<< ans2 << endl; // first best and second best
		
	}
}
