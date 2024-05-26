#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define int long long
using namespace std;	
	
	
vector<vector<int>> g;
vector<int>vis;
int n,m,a,b,cnt;

void bfs(int u){
	queue<int>q;
	q.push(u);
	vis[u]=1;
	while( q.size() ){
		int u = q.front();q.pop();
		cnt++;
		for(auto v:g[u]){
			if(!vis[v]){
				q.push(v);
				vis[v]=1;
			}
		}
	}
}
	
	
int32_t main(){   
	int q;cin>>q;
	while(q--){
		cin >>n >>m >>a >> b;
		g = vector<vector<int>>(n+1);
		vis = vector<int>(n+1);
		for(int i=0;i<m;i++){
			int u,v;cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		
		fill(vis.begin(),vis.end(),0);
		cnt = 0;
		vis[b]=1;
		bfs(a);
		int x = n - cnt-1;
		
		fill(vis.begin(),vis.end(),0);
		cnt = 0;
		vis[a]=1;
		bfs(b);
		int y = n - cnt-1;
		
		cout << x * y << endl;	
	}	
}




