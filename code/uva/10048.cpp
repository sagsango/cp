#include<bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N = 100;
int d[N+1][N+1];
int32_t main()
{
	int c,s,q,u,v,w,T=0;
	while( ++T, cin >> c >> s >> q && c && s && q )
	{
		for(int i=1;i<=c;i++)
		for(int j=1;j<=c;j++)
		d[i][j]=(i==j?0:1e15);
		
		for(int i=1;i<=s;i++)
		{
			cin>>u>>v>>w;
			d[u][v]=w;
			d[v][u]=w;
		}
		
		for(int i=1;i<=c;i++)
		for(int j=1;j<=c;j++)
		for(int k=1;k<=c;k++)
		d[j][k]=min(d[j][k],max(d[j][i],d[i][k]));
		
		if(T!=1)cout<<endl;
		cout<<"Case #"<<T<<endl;
		for(int t=1;t<=q;t++)
		{
			cin>>u>>v;
			if(d[u][v] <= 1e4)cout<<d[u][v]<<endl;
			else cout<<"no path"<<endl;
		}
	}

	
}
