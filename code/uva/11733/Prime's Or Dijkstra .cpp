
#include<bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
 
const int N = 10000 , M = 100000;
int n,m,A;

int32_t main()
{
	IOS	
	int T;cin>>T;
	for(int t=1;t<=T;t++)
	{
		
		cin>>n>>m>>A;
		vector<vector<pair<int,int>>>g(n+1);
		for(int i=1;i<=m;i++)
		{
			int u,v,w;cin>>u>>v>>w;
			g[u].push_back({v,w});
			g[v].push_back({u,w});
		}
		// Prime's from every Node
		vector<int>d(n+1,A);
		vector<int>vis(n+1);
		priority_queue< pair<int,int> , vector<pair<int,int>> ,greater<pair<int,int>> > pq;
		for(int i=1;i<=n;i++)
		pq.push({d[i],i});
		while( pq.size() )
		{
			int u=pq.top().second;pq.pop();
			if(vis[u])continue;
			vis[u]=1;
			for(auto it:g[u])
			{
				int v = it.first;
				int w = it.second;
				if(!vis[v] && d[v] > w )
				{
					d[v]=w;
					pq.push({d[v],v});
				}
			}
		}
		int airPort = 0;
		int cost    = 0;
		for(int i=1;i<=n;i++)
		{
			cost+=d[i];
			airPort+=d[i]==A;
		}
		cout<<"Case #"<<t<<": "<< cost << " "<< airPort << endl;
	}
}
