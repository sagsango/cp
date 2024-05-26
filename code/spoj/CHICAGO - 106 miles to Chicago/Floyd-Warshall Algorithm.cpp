/* Floyd-Warshall Algorithm */
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
 
const int N = 100;
long double d[N+1][N+1];
int n,m;
int32_t main()
{
	IOS
	while(cin>>n && n)
	{
		cin>>m;
		for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
		d[i][j]=(i==j ? 1 : 0);
	
		for(int i=1;i<=m;i++)
		{
			int u,v;cin>>u>>v;
			long double p;cin>>p;
			d[u][v]=p/100;
			d[v][u]=p/100;
		}
	
		for(int i=1;i<=n;i++)//add ith vertex
		for(int j=1;j<=n;j++)
		for(int k=1;k<=n;k++)
		d[j][k]=max(d[j][k],d[j][i]*d[i][k]);//relax all path through i
	
		cout << fixed << setprecision(6) << d[1][n]*100 << " percent" <<endl;
	}	
}
