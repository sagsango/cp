#include <iostream>
#include <queue>
#include <vector>
#include <string>
#define int long long
using namespace std;	
#define INF 0x3f3f3f3f
const int dx[4] = {0,0,1,-1};
const int dy[4] = {+1,-1,0,0};

bool valid(int x,int y,int n,int m){
	return x >= 0 && x < n && y >= 0 && y < m ;
}

int32_t main(){
	int n,m,k;cin>>n>>m>>k;
	vector<vector<int>>vis(n,vector<int>(m));
	vector<vector<int>>dis(n,vector<int>(m,INF));
	vector<string>s(n);
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
	x1--,y1--,x2--,y2--;
	queue<pair<int,int>>q;
	q.push({x1,y1});
	dis[x1][y1]=0;
	while( q.size() ){
		int ux = q.front().first;
		int uy = q.front().second;
		q.pop();
		for(int i=0;i<4;i++){
			for(int j=1;j<=k;j++){
				int vx = ux + j*dx[i];
				int vy = uy + j*dy[i];
				if( !valid(vx,vy,n,m) || s[vx][vy]=='#' || dis[vx][vy] <= dis[ux][uy])break;
				if( dis[vx][vy] > dis[ux][uy]+1)
				{
					dis[vx][vy]=dis[ux][uy]+1;
				    q.push({vx,vy});
				}
			}
		}
	}
	cout << ( dis[x2][y2] < INF ? dis[x2][y2] : -1 ) << endl;
}

