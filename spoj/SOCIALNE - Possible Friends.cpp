#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N = 50;
int d[N][N];
vector<string>g(N);
int n;
int32_t main()
{
	IOS
	int q;cin>>q;
	while(q--)
	{
		cin >> g[0];
		n = g[0].size();
		for(int i=1;i<n;i++)
		cin>>g[i];
		
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			if( i==j )d[i][j]=0;
			else d[i][j]=( g[i][j]=='Y' ? 1 : 1e15 );
		}
		
		for(int i=0;i<n;i++)/*adding ith vertex to our graph*/
		for(int j=0;j<n;j++)
		for(int k=0;k<n;k++)
		d[j][k]=min(d[j][k],d[j][i]+d[i][k]);/*relaxing path of every other vertex passing thorugh i*/
		
		int mxpf = 0;
		int id   = 0;
		
		for(int i=0;i<n;i++)
		{
			int cnt = 0;
			for(int j=0;j<n;j++)
			cnt+=d[i][j]==2;
			if( cnt > mxpf )
			{
				mxpf = cnt;
				id = i;
			}
		}
		cout << id <<" "<< mxpf << endl;
	}
		
		
		
}
