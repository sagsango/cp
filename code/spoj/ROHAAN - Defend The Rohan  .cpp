#include<bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N = 50;
int d[N+1][N+1];
int T,t,n,q,u,v,sum;
int32_t main()
{
	IOS
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		cin >> n;
		
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		cin>>d[i][j];
		
		for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
		
		cin>>q;
		sum=0;
		while(q--)
		{
			cin>>u>>v;
			sum+=d[u][v];
		}
		
		cout <<"Case #"<<t<<": "<< sum << endl;
	}
}
	

