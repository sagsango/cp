// https://www.spoj.com/problems/WATER/


#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

/*****************************************************************************************************************
 * O(n*m*log(n*m))
 * Water level problem asked in kickstart: Complexity used there O(n*m *n*m * log(MaxH)) , bfs with binary search
 ****************************************************************************************************************/
 
struct box {
	int  h , x , y ;
	bool operator < ( const box& other ) const {
		return h > other.h;
	}
};
int dx[4]={+1,-1,+0,-0};
int dy[4]={+0,-0,+1,-1};
int32_t main()
{
	IOS
	int q;cin>>q;
	while(q--)
	{
		int n , m; cin >> n >> m;
		vector<vector<int>>h(n+2,vector<int>(m+2));
		vector<vector<int>>vis(n+2,vector<int>(m+2));
		for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		cin>>h[i][j];
		
		//mark grid outside  as visited
		for(int i = 0 ; i <= n + 1; i++ )
		for(int j = 0 ; j <= m + 1; j++ )
		{
			if( i==0 || j==0 || i==n+1 || j==m+1 )
			{
				vis[i][j]=1;
			}
		}
		
		// min heap priority queue
		priority_queue<box>pq;
		
		
		// push all elements at corner in priority queue and make them visited
		for(int i=1;i<=n;i++)
		{
			pq.push({h[i][1],i,1});
			pq.push({h[i][m],i,m});
			vis[i][1]=1;
			vis[i][m]=1;
		}
		for(int j=1;j<=m;j++)
		{
			pq.push({h[1][j],1,j});
			pq.push({h[n][j],n,j});
			vis[1][j]=1;
			vis[n][j]=1;
		}
		
		
		int ans = 0 ;
		while( pq.size() )
		{
			//extract curr min elemnt 
			box u = pq.top();pq.pop();
			queue<pair<int,int>>q;
			q.push({u.x,u.y});
			
			//do bfs: 
			while( q.size() )
			{
				pair<int,int> v = q.front(); q.pop();
				for(int k = 0 ; k < 4 ; k++ )
				{
					int x = v.first + dx[k];
					int y = v.second+ dy[k];
					
					if( vis[x][y] )continue;
					vis[x][y]=1;
					
					//if curr h less than source then it will not form any boundary and will have water above it Hsource-Hcurr
					if( h[x][y]  < u.h )
					{
						ans+= u.h - h[x][y];
						q.push({x,y});
						/* because pq is minheap and q will contain only h < Hsource so you can use pq for bfs also [complexity will be litter worse], then do not need to use queue */
					}
					else pq.push({h[x][y],x,y}); // It will form a boundary so push it into priority queue
					
				}
			}
		}
		cout << ans << endl;
	}
					
}




