#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define int long long
using namespace std;	


const int maxn = 5000;
vector<int>g[maxn+1];
vector<int>vis(maxn+1);
vector<int>topo;
int n,m,s,cnt=0;


void dfs(int u){
	vis[u]=1;
	for(auto v:g[u]){
		if(!vis[v]){
			dfs(v);
		}
	}
	topo.push_back(u);
}


void bfs(int u){
	queue<int>q;
	q.push(u);
	vis[u]=1;
	while( q.size() ){
		int u = q.front(); q.pop();
		for(auto v:g[u]){
			if(!vis[v]){
				vis[v]=1;
				q.push(v);
			}
		}
	}
}


int32_t main(){   
	cin>>n>>m>>s;
	for(int i=1;i<=m;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			dfs(i);
		}
	}
	reverse(topo.begin(),topo.end());
	fill(vis.begin(),vis.begin()+n+1,0);

	bfs(s);
	for(int i=0;i<n;i++){
		int u = topo[i];
		if(!vis[u]){
			bfs(u);
			cnt++;
		}
	}
	cout<<cnt<<endl;
}



