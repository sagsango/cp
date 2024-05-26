#include<bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N = 100;
int d[N][N];
int n;
int32_t main()
{
	while( cin>>n )
	{
		for(int i=0;i<n;i++)
		d[i][i]=0;
	
		for(int i=1;i<n;i++)
		for(int j=0;j<i;j++)
		{
			string s;cin>>s;
			if( s=="x" )d[i][j]=d[j][i]=1e15;
			else
			{
				stringstream strm(s);
				int w; strm>>w;
				d[i][j]=d[j][i]=w;
			}
		}
	
		for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
		
		int mx = 0;
		for(int i=1;i<n;i++)
		mx = ( d[0][i] > mx ? d[0][i] : mx);
		
		cout << mx << endl;
	}
}
