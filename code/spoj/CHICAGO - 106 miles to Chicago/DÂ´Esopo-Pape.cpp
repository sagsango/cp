#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
 
 
int32_t main()
{
    IOS
    int n,m;
    while( cin >> n   && n )
    {
		cin >> m ;
		vector<pair<int,long double>>g[n+1];
		for(int i=1;i<=m;i++)
		{
			int u,v;cin>>u>>v;
			long double w;cin>>w;
			w/=100;
			g[u].push_back({v,w});
			g[v].push_back({u,w});
		}
		vector<int>clr(n+1,2);  // 0 : has relaexed, 1:being relax 2:yet to relax
		vector<long double>d(n+1);
		deque<int>q;
		d[1]=1;
		q.push_front(1);
		while( q.size() )
		{
			int u = q.front();q.pop_front();
			clr[u] = 0;
			for(auto it:g[u])
			{
				int v = it.first;
				long double w = it.second;
				if( d[v] < d[u]*w )
				{
					d[v]=d[u]*w;
					if( clr[v] == 0 )
					{
						q.push_front(v);
						clr[v]=1;
					}
					else if( clr[v] == 2 )
					{
						q.push_back(v);
						clr[v]=1;
					}
					
				}
			}
		}
		 cout << fixed << setprecision(6) << d[n]*100 <<" "<<"percent"<<endl;
	 }
}
 
