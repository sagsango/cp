#include<bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
 
struct Edge{
	int v,w,id;
};
const int N = 100000 , M = 1000000;
vector<vector<Edge>>g(N+1);
vector<int>par(N+1);
vector<int>usedE(M+1);
vector<int>U(M+1),V(M+1),W(M+1);
int n,m;
 
int primes(int s=1 )
{
	vector<int>d(n+1,1e15);
	vector<int>edgeid(n+1);
	vector<int>vis(n+1);
	priority_queue< pair<int,int> , vector< pair<int,int> > , greater<pair<int,int>> >pq;
	d[s]=0;
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
			if( !vis[v] && d[v] > w )
			{
				d[v]=w;
				edgeid[v]=id;
				par[v]=u;
				pq.push({d[v],v});
			}
		}
	}
	int min_spaning_wt = 0;
	for(int i=1;i<=n;i++)
	{
		usedE[ edgeid[i] ]=1;
		min_spaning_wt+=d[i];
		//cout << i <<"::"<<edgeid[i] <<" "<< par[i] <<" "<< d[i]<<endl;
	}
	return min_spaning_wt;
}
	
 
int32_t main()
{
	IOS
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>U[i]>>V[i]>>W[i];
		g[ U[i] ].push_back({V[i],W[i],i});
		g[ V[i] ].push_back({U[i],W[i],i});
	}
	cout << primes() << endl;
		
		
	
}
