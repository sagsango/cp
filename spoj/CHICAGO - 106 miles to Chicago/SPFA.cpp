/* SPFA */
 
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
		vector<int>inq(n+1);
		vector<long double>d(n+1);
		queue<int>q;
		d[1]=1;
		q.push(1);
		inq[1]=1;
		while( q.size() )
		{
			int u = q.front();q.pop();
			inq[u]=0;
			for(auto it:g[u])
			{
				int v = it.first;
				long double w = it.second;
				if( d[v] < d[u]*w )
				{
					d[v]=d[u]*w;
					if(!inq[v])
					{
						q.push(v);
						inq[v]=1;
					}
				}
			}
		}
		 cout << fixed << setprecision(6) << d[n]*100 <<" "<<"percent"<<endl;
	 }
}
 
