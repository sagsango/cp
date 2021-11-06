#include <string>
#include <vector>
#include <iostream>
using namespace std;

int n, m;
vector<vector<int>> g, gr, vis, dp;


int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while( t-- ){
		cin >> n >> m;
		vector<string>s(n);
		for(int i=0;i<n;++i){
			cin >> s[i];
		}
		g = gr = vis = vector<vector<int>>(n*m);
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				int x = i, y = j;
				switch(s[i][j]){
					case 'L';
						y -= 1; break;
					case 'R':
						y += 1; break;
					case 'U':
						x -= 1; break;
					case 'D':
						x += 1; break;
				}
				if( x < n && x >= 0 && y < m && y >= 0 ){
					g[i*m+j].push_back(x*m+y);
					gr[x*m+y].push_back(i*m+j);
				}
			}
		}
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				if( !vis[i*m+j] ){
					dfs(i*m+j);
				}
			}
		}

	}

