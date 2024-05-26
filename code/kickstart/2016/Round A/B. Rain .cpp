#include<bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

vector<int>dx={+1,-1,+0,+0};
vector<int>dy={+0,+0,+1,-1};

int is_possible(int x,int y,int h,int n,int m,vector<vector<int>>&a)
{
	queue< pair<int,int> >q;
	vector<vector<bool>>vis(n+2,vector<bool>(m+2));
	q.push({x,y});
	vis[x][y]=1;
	while( q.size() )
	{
		int  x = q.front().first;
		int  y = q.front().second;
		
		q.pop();
		
		if( a[x][y]==0)return 0;
		if( a[x][y]>=h)continue;
		
		for(int i=0;i<4;i++)
		if(!vis[x+dx[i]][y+dy[i]])
		{
			vis[x+dx[i]][y+dy[i]]=1;
			q.push({x+dx[i],y+dy[i]});
		}
	}
	return 1;
}
int32_t main()
{
	IOS
	int T;cin>>T;
	for(int t=1;t<=T;t++)
	{
		int n,m;cin>>n>>m;
		vector<vector<int>>a(n+2,vector<int>(m+2));
		for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		cin>>a[i][j];
		
		int ans=0;
		for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			int l=1,r=1000-a[i][j];
			int mx=0;
			while( l <= r )
			{
				int mid = (l+r)/2;
				if( is_possible( i,j,a[i][j]+ mid , n , m , a) )
				{
					mx=max(mx,mid);
					l=mid+1;
				}
				else r=mid-1;
			}
			ans+=mx;
		}

		cout<<"Case #"<<t<<": "<<ans<<endl;
	}
}
 
