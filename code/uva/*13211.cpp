#include<bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N = 500;
int d[N][N];
int used[N],a[N];
int T,t,n,sum;
int32_t main()
{
	IOS
	cin>>T;
	for(int t=0;t<T;t++)
	{
		cin >> n;
		for(int i=0;i<n;i++)
		used[i]=0;
		
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		cin>>d[i][j];
		
		for(int i=0;i<n;i++)
		cin>>a[i];
		
		sum=0;
		for(int i=0;i<n;i++)
		{
			int u=a[n-i-1];
			used[u]=1;
			for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				d[i][j]=min(d[i][j],d[i][u]+d[u][j]);
				sum+=d[i][j]*used[i]*used[j];
			}
		}
		cout << sum << endl;
	}
}
	

