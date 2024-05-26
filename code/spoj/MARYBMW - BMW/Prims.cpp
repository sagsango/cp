/*
  Prims
  No neg cycle
  Undirected only  [ besauce all the vertix may not be recahble from s / you have to check from every vertex as s]
  Multiple edges valid
*/
#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
 
struct Edge{
	int v,w,id;
};
const int N = 100'000 , M = 1000'000;
vector<vector<Edge>>g;
vector<int>par(N+1);          // parent of every node
vector<int>used(M+1);         // pertcular edge id has been used or not
vector<int>U(M+1),V(M+1),W(M+1);
int n,m;
 
int prims(int s=1 )
{
	/*      set size of the graph           */     
	
	
	//////// Multiple tests  ///////////
	fill(par.begin(),par.begin()+n+1,0);
	fill(used.begin(),used.begin()+m+1,0);
	////////////////////////////////////
	
	
	/* chenge distance initialisation */
	vector<int>d(n+1,0);
	vector<int>edgeid(n+1);
	vector<int>vis(n+1);
	
	/* Change priority queue type */
	priority_queue< pair<int,int> > pq;
	
	
	d[s]=1e18;   /* change source distance */
	
	pq.push({d[s],s});
	while( pq.size() )
	{
		int u=pq.top().second ; pq.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto it:g[u])
		{
			int v=it.v;
			int id=it.id;
			int w =it.w;
			
			/* chenge relaxsation */
			if( !vis[v] && d[v] < min(w,d[u]) )// !vis[v] meanse v has relaxed all his neibhours &  u  will not going to relax v again with same edge.
			{
				d[v]=min(w,d[u]);
				edgeid[v]=id;
				par[v]=u;
				pq.push({d[v],v});
			}
		}
	}
	
	return d[n] ? d[n] : -1 ;
	
	/*
	int min_spaning_wt = 0;
	for(int i=1;i<=n;i++)
	{
		used[ edgeid[i] ]=1;
		min_spaning_wt+=d[i];
	}
	return min_spaning_wt;
	*/
}
	
 
int32_t main()
{
	IOS
	int q;cin>>q;
	while(q--)
	{
		cin>>n>>m;
		g=vector<vector<Edge>>(n+1);
		
		for(int i=1;i<=m;i++)
		{
			cin>>U[i]>>V[i]>>W[i];
			g[ U[i] ].push_back({V[i],W[i],i});
			g[ V[i] ].push_back({U[i],W[i],i});
		}
		cout << prims() << endl;
		
		
	}
}
 
