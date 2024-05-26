#include<bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N = 100;
int d[N+1][N+1];
int32_t main()
{
	IOS
	int T;cin>>T;
	for(int t=1;t<=T;t++)
	{
		int n,m;cin>>n>>m;
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		d[i][j]=(i==j?0:1e15);
		
		for(int i=1;i<=m;i++)
		{
			int u,v,w;cin>>u>>v>>w;
			d[u][v]=d[v][u]=min(d[u][v],w);//multiple edges
		}
		
		for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
		
		int far_dis = 1e12;
		for(int i=6;i<=n;i++)
		{
			int curr_far = 0;
			for(int j=1;j<=n;j++)if( curr_far < d[i][j] )curr_far = d[i][j];
			if( d[i][1] == d[i][2] && d[i][2] == d[i][3] && d[i][3] == d[i][4] && d[i][4] == d[i][5]  && curr_far < far_dis ) 
			{
				far_dis = curr_far;
			}
		}
		cout <<"Map "<<t<<": "<< ( far_dis < 1e9 ? far_dis : -1 ) << endl;
	}
		
	
	
}
	

