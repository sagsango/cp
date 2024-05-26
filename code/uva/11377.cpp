#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int n , m , k ,q;
vector<vector<int>>g;
vector<int>a;
vector<int>d;

vector<int> dijkstra(int u)
{
	// vertex from 1 to n
	vector<int>d(n+1,1e15);
	vector<int>vis(n+1);
	d[u]=a[u]^1;
	priority_queue< pair< int,int > , vector< pair<int,int> > , greater< pair<int,int> > >pq;
	pq.push({d[u],u});
	while( pq.size() )
	{
		int u = pq.top().second;pq.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto it:g[u])
		{
			int v = it;
			if( d[v] > d[u] + (a[v]^1) )
			{
				d[v]=d[u]+(a[v]^1);
				pq.push({d[v],v});
			}
		}
	}
	return d;
}


int32_t main()
{
	IOS
	int T;cin>>T;
	for(int t=1;t<=T;t++)
	{
		 cin >> n >> m >> k;
		 g=vector<vector<int>>(n+1);
		 a=vector<int>(n+1);
		 for(int i=1;i<=k;i++)
		 {
			 int x;cin>>x;
			 a[x]=1;
		 }
		 for(int i=1;i<=m;i++)
		 {
			 int u,v; cin >> u >> v;
			 g[u].push_back(v);
			 g[v].push_back(u);
		 }
		 cin >> q;
		 cout <<"Case "<<t<<": "<<endl;
   		 while(q--)
   		 {
			 int u , v; cin >> u >> v;
			 d = dijkstra(u);
			 if( u == v ) d[u]=0;
			 cout << ( d[v] < 1e12 ? d[v] : -1 ) << endl;
		 }
		 cout << endl;
		 
	 }	
}
	
	
