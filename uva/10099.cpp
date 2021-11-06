#include<bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N = 100;
int cap[N+1][N+1];
int32_t main()
{
	IOS
	int n , r ,s , d , t, tc=0;
	while( ++tc,cin >> n >> r && ( n || r ) )
	{
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		cap[i][j]=(i==j?1e15:0); // capcity of road i to j
		
		for(int i=1;i<=r;i++)
		{
			int u,v,mxc;cin>>u>>v>>mxc;
			cap[u][v]=cap[v][u]=max(cap[u][v],mxc);// handing multiple bus services betwwen a pair of city
		}
		
		cin>> s >> d >> t;
		
		for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		cap[i][j]=max(cap[i][j],min(cap[i][k],cap[k][j]));
		
		cout << "Scenario #"<<tc<<endl;
		cout << "Minimum Number of Trips = "<< (t+cap[s][d]-2)/(cap[s][d]-1) << endl; // guide will be added to every trip
		
		cout << endl;
	}
		
		
		
		
	
	
}
	

