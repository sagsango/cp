#include<bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

struct EdgeBox{
	int u,v,w,id;
};

const int N = 100,M=1000;
vector<int>dis(N+1);
vector<int>inq(N+1);
vector<int>vis(N+1);
vector<vector<pair<int,int>>>g(N+1);
vector<EdgeBox>edge(M+1);
int n,m,L;
int cost_before ,cost_after;

void spfa(int s,int bad)  // Use SPfa
{
	for(int i=1;i<=n;i++)
	dis[i]=1e15,inq[i]=0;
	
	dis[s]=0;
	queue<int>q;
	q.push(s);
	
	while(q.size())
	{
		int u=q.front();q.pop();
		inq[u]=0;
		for(auto it:g[u])
		{
			int v = it.first;
			int id= it.second;
			if( id == bad )continue;
			if( dis[v] > dis[u] + edge[id].w )
			{
				dis[v]=dis[u]+edge[id].w;
				if( !inq[v] )
				{
					inq[v]=1;
					q.push(v);
				}
			}
		}
	}
}
void dijskta(int s,int bad) // Use Dijkstra
{
	for(int i=1;i<=n;i++)
	dis[i]=1e15,vis[i]=0;
	
	dis[s]=0;
	priority_queue< pair<int,int> , vector<pair<int,int>> , greater< pair<int,int> > > pq;
	pq.push({dis[s],s});
	
	while(pq.size())
	{
		int u=pq.top().second;pq.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto it:g[u])
		{
			int v = it.first;
			int id= it.second;
			if( id == bad )continue;
			if( dis[v] > dis[u] + edge[id].w )
			{
				dis[v]=dis[u]+edge[id].w;
				pq.push({dis[v],v});
			}
		}
	}
}
	

int32_t main()
{
	IOS
	while( cin >> n >> m >> L )
	{
		for(int i=1;i<=n;i++)
		g[i].clear();
		cost_after=0;
		cost_before=0;
		
		for(int i=1;i<=m;i++)
		{
			cin >> edge[i].u >> edge[i].v >> edge[i].w ; edge[i].id=i;
			g[ edge[i].u ].push_back({edge[i].v,i});
			g[ edge[i].v ].push_back({edge[i].u,i});
		}
		
		/* O(m*n) */
		for(int i=1;i<=n;i++) //O(n)
		{
			int bad_id = 0;
			spfa(i,bad_id); // O(m)
			for(int i=1;i<=n;i++) // O(n)
			cost_before+=( dis[i] < 1e15 ? dis[i] : L );
		}
		
		/* O(m*m*n) */
		for(int i=1;i<=m;i++) // O(m)
		{
			int bad_id = i;
			int curr_cost=0;
			for(int i=1;i<=n;i++) // O(n)
			{
				spfa(i,bad_id); // O(m)
				for(int i=1;i<=n;i++) // O(n)
				curr_cost+=( dis[i] < 1e15 ? dis[i] : L );
			}
			cost_after=max(curr_cost,cost_after);
		}
		
		cout << cost_before <<" "<< cost_after << endl;
	}
		
		
	
}
	

