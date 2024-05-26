#include <iostream>
#include <string>
#include <queue>
using namespace std;

const int dx[]={-1,1,0,0}, dy[]={0,0,-1,1};
int N, M, D[1000][1000];
vector<string> F;
vector<int> s;

bool valid_coord(int x, int y){
	return 0<=x && x<N && 0<=y && y<M && F[x][y]=='.';
}

int main(){
	int p, cnt=0, ans[10]={};
	queue<pair<int,int>> Q[10];
	cin>>N>>M>>p;
	F.resize(N);
	s.resize(p);
	for(int i=0;i<p;i++) cin>>s[i];
	for(int i=0;i<N;i++) {
		cin>>F[i];
		for(int j=0;j<M;j++) {
			if('1'<=F[i][j] && F[i][j]<='9') {
				Q[F[i][j]-'1'].push({i,j});
				ans[F[i][j]-'1']++;
			}
			else if(F[i][j]=='.') cnt++;
		}
	}
	while(cnt) {
		int x, y;
		bool changed=false;
		queue<pair<int,int>> T;
		for(int i=0;i<p;i++) {
			while(!Q[i].empty()) {
				tie(x,y)=Q[i].front();
				Q[i].pop();
				for(int k=0;k<4;k++) {
					if(valid_coord(x+dx[k],y+dy[k])) {
						D[x+dx[k]][y+dy[k]]=1;
						F[x+dx[k]][y+dy[k]]=i+'1';
						ans[i]++; cnt--;
						T.push({x+dx[k],y+dy[k]});
						changed=true;
					}
				}
			}
			if(cnt==0) break;
			while(!T.empty()) {
				tie(x,y)=T.front();
				T.pop();
				if(s[i]==1) {
					Q[i].push({x,y});
					continue;
				}
				for(int k=0;k<4;k++) {
					if(valid_coord(x+dx[k],y+dy[k])) {
						F[x+dx[k]][y+dy[k]]=i+'1';
						D[x+dx[k]][y+dy[k]]=D[x][y]+1;
						ans[i]++; cnt--;
						if(D[x+dx[k]][y+dy[k]]=(D[x][y]+1)%s[i]) T.push({x+dx[k],y+dy[k]});// have to cover in curr bfs
						else Q[i].push({x+dx[k],y+dy[k]}); // have to cover in next bfs
					}
				}
			}
		}
		if(!changed) break;
	}
	for(int i=0;i<p;i++) cout<<ans[i]<<' ';
	return 0;
}

