// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1665
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N = 50;
long double x[N],y[N],d[N][N],td[N][N];
int32_t main()
{
	IOS
	int n , m ; 
	while( cin >> n >> m && ( n || m ) )
	{
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			d[i][j] = (i==j ? 0 : 1e8);
		}
		
		for(int i=0;i<n;i++)
		cin>>x[i]>>y[i];
		for(int i=0;i<m;i++)
		{
			int u,v;cin>>u>>v;
			u--;v--;
			d[u][v]=d[v][u]=sqrt( (x[u]-x[v])*(x[u]-x[v]) + (y[u]-y[v])*(y[u]-y[v]) );
		}
		

		for(int i=0;i<n;i++)/* adding new vertex i */
		for(int j=0;j<n;j++)
		for(int k=0;k<n;k++)
		{
			d[j][k]=min(d[j][k],d[j][i]+d[i][k]);/* Relax all path passing through i */
		}
		
		long double dsum = 0 , duv = 0;
		int u = -1 , v = -1 ;
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			dsum+=d[i][j];
		}
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{		
				long double dij,dji;
				dij=dji = sqrt( (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]) );
				
				long double tdsum=0;
				for(int k=0;k<n;k++)
				for(int l=0;l<n;l++)
				{
					tdsum+=min({d[k][l],d[k][i]+dij+d[j][l],d[k][j]+dji+d[i][l]});
				}
				
				if( ( dsum - tdsum >= 1e-6 ) || ((dsum - tdsum) <= 1e-6 && duv - dij >= 1e-6) )
				{
					dsum = tdsum;
					u =i;
					v =j;
				}
		}
		if( u!=-1 && v!=-1 )cout << u+1 <<" "<< v+1 << endl;
		else cout << "No road required" << endl;
	}
}
