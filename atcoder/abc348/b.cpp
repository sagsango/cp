#include<iostream>
#include<map>
#include<queue>
#define int long long
using namespace std;
typedef pair<int,int> PII;
int mod=998244353;
const int N=210;
char g[N][N];
int w[N][N];
bool vis[N][N];
int h,m;
int sx,sy,ex,ey;
bool flag=0;
queue<PII> q;
int dist[N][N];
bool check(int x,int y){
	if(x<1||x>h||y<1||y>m) return 0;
	if(g[x][y]=='#') return 0;
	return 1;
}
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
bool bfs(){
	q.push({sx,sy});
	dist[sx][sy]=w[sx][sy];
	while(q.size()){
		auto t=q.front();
		q.pop();
	//	w[t.first][t.second]=0;
		if(t.first==ex&&t.second==ey) return 1;
		if(dist[t.first][t.second]<=0) continue;
		for(int i=0;i<4;i++){
			int xx=dx[i]+t.first;
			int yy=dy[i]+t.second;
			if(check(xx,yy)){
				if(!vis[xx][yy]){
					vis[xx][yy]=1;
					dist[xx][yy]=max(dist[t.first][t.second]-1,w[xx][yy]);
					q.push({xx,yy});
					vis[xx][yy]=1;
				}
				if(dist[xx][yy]<dist[t.first][t.second]-1){
					dist[xx][yy]=dist[t.first][t.second]-1;
					q.push({xx,yy});
				}
			}
		}
	}
	return 0;
}
signed main(){
	cin>>h>>m;
	for(int i=1;i<=h;i++){
		for(int j=1;j<=m;j++){
			cin>>g[i][j];
			if(g[i][j]=='S') sx=i,sy=j;
			if(g[i][j]=='T') ex=i,ey=j;
		}
	}
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int r,c,e;
		cin>>r>>c>>e;
		w[r][c]=e;
	}
	if(bfs()) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}