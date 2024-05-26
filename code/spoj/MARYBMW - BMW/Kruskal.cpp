/*
  Kruskal's
  No neg cycle
  Undirected only
  Multiple edges valid
*/
#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
 
const int N = 100000 , M = 1000000;
vector<int>U(M+1),V(M+1),W(M+1);
vector<int>used(M+1);
int n,m;
 
////////////////////  Kruskal's MST  ////////////////////////////
vector<int>par(N+1,-1);
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
	fill(used.begin(),used.begin()+m+1,0);
	fill(par.begin(),par.begin()+n+1,-1);
	
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
////////////////////////////////////////////////////////////
 
int32_t main()
{
     IOS
     int q;cin>>q;
     while(q--)
     {
		
    	cin>>n>>m;
    	for(int i=1;i<=m;i++)
    	cin>>U[i]>>V[i]>>W[i];
    	kruskal();
 
    	vector<vector<pair<int,int>>>g(n+1);
    	for(int i=1;i<=m;i++)
    	{
    		if(used[i])
    		{
    			g[U[i]].push_back({V[i],W[i]});
    			g[V[i]].push_back({U[i],W[i]});
    		}
    	}
    	vector<int>maxspeed(n+1,0);
    	vector<int>vis(n+1);
    	maxspeed[1]=1e18;
    	queue<int>q;
    	q.push(1);
    	vis[1]=1;
    	
    	int ans = -1;
    	while(q.size())
    	{
    		int u=q.front();q.pop();
    		if( u==n )
    		{
    			ans=maxspeed[u];
    			break;
    		}
    		for(auto it:g[u])
    		{
    			int v=it.first;
    			int w=it.second;
    			if( !vis[v] )
    			{
    				vis[v]=1;
    				maxspeed[v]=min(maxspeed[u],w);
    				q.push(v);
    			}
    		}
    	}
        cout<<ans<<endl;
   }
}
 
