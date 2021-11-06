#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N = 100;
long double d[N+1][N+1];
int32_t main()
{
	IOS
	int u , v , t=0;
	while( ++t , cin >> u >> v && ( u && v ) )
	{
		for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
		d[i][j]=( i==j ? 0 : 1e15 );
		
		d[u][v]=1;
		while( cin >> u >> v && (u && v) )
		{
			d[u][v]=1;
		}
		
		for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
		for(int k=1;k<=N;k++)
		d[j][k]=min(d[j][k],d[j][i]+d[i][k]);
		
		long double sum = 0,cnt=0;
		for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
		{
			if(i==j || d[i][j] > 1e8 )continue;
			cnt++;
			sum+=d[i][j];
		}
		
		cout <<"Case "<<t<<": average length between pages = "<<fixed << setprecision(3) << sum/cnt <<" clicks"<<endl;
		
	}
}
