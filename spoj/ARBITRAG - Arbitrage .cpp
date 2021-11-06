#include<bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;


const int N = 30;
int t=0,n,m;
string u,v;
float w , conversion[N][N];
int32_t main()
{
	IOS
	while( t++ , cin>>n && n )
	{
		map<string,int>NameId;
		
		for(int i=0;i<n;i++)
		cin>>u,NameId[u]=i;
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			conversion[i][j]=0;
			
			conversion[i][i]=1;
		}
		
		cin>>m;
		for(int i=0;i<m;i++)
		{
			cin>>u>>w>>v;
			conversion[ NameId[u] ][ NameId[v] ]=w;
		}
		
		for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		conversion[i][j]=max(conversion[i][j],conversion[i][k] * conversion[k][j]);
		
		int ok = 0;
		for(int i=0;i<n;i++)
		ok |= (conversion[i][i] > 1.00);
		
		cout << "Case "<<t<<": "<<( ok ? "Yes" : "No" )<< endl;
	}
			
}
	

