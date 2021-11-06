#include<bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
 
const int N = 20000 , M = 100000;
vector<int>U(M+1),V(M+1),W(M+1);
vector<int>used(M+1);
int n,m,s;
 
////////////////////  Kruskal's MST  ////////////////////////////////////////////////
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
	return W[a] > W[b];
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
//////////////////////////////////////////////////////////////////////////////////////////







const int lgN = 20 , inf = 1e7;
vector<vector<pair<int,int>>>g;
vector<int> tin;
vector<int> tout;
vector<vector<int>>up;
vector<vector<int>>mnw; // Initialise with +inf.
int t=0;

////////////////////// Binary Lifting ////////////////////////////////////////////////////
void dfs(int u=1,int p=0,int w=0)
{
	tin[u]=++t;
	up[u][0]=p;
	mnw[u][0]=( p ? w : +inf);
	for(int i=1;i<=lgN;i++)
	{
		up[u][i]=up[ up[u][i-1] ][i-1];
		mnw[u][i]=min(mnw[ up[u][i-1] ][i-1],mnw[u][i-1]);
	}
	for(auto it:g[u])
	{
		int v=it.first;
		int w=it.second;
		if( v!= p)
		{
			dfs(v,u,w);
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

int MinWeightQuery(int u,int v)
{
	int l = LCA(u,v);
	int mn = +inf;
	if( u!=l )
	{
		for(int i=lgN;i>=0;i--)
	    if( up[u][i] && !isAncestor(up[u][i],l))
	    {
			mn=min(mn,mnw[u][i]);
			u=up[u][i];
		}
		mn=min(mn,mnw[u][0]);
	}
	if( v!=l )
	{
		for(int i=lgN;i>=0;i--)
	    if( up[v][i] && !isAncestor(up[v][i],l))
	    {
			mn=min(mn,mnw[v][i]);
			v=up[v][i];
		}
		mn=min(mn,mnw[v][0]);
	}
	return mn;
}

void initBinaryLifting()
{
	t=0;
	g=vector<vector<pair<int,int>>>(n+1);
    tin=vector<int>(n+1);
    tout=vector<int>(n+1);
    up=vector<vector<int>>(n+1,vector<int>(lgN+1));
    mnw=vector<vector<int>>(n+1,vector<int>(lgN+1,+inf)); // Initialise with +inf.
}
	
////////////////////////////////////////////////////////////////////////////////////////


	
int32_t main()
{
	IOS	
	while( cin >> n >> m >> s )
	{
		for(int i=1;i<=m;i++)
		cin>>U[i]>>V[i]>>W[i];
		
		kruskal();
		initBinaryLifting();
		
		for(int i=1;i<=m;i++)
		{
			if( used[i] )
			{
				g[U[i]].push_back({V[i],W[i]});
				g[V[i]].push_back({U[i],W[i]});
			}
		}
		
		dfs();
		
		while( s-- )
		{
			int u,v;cin>>u>>v;
			cout<< MinWeightQuery(u,v) << endl;
		}
		
		
	}
}
