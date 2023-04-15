#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int main(){
	int n, m; cin >> n >> m;
	vector<pair<int,int>> g[n+1];
	for(int i=1;i<=m;++i){
		int u, v, w; cin >> u >> v >> w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	vector<long long>dis(n+1,1e15), par(n+1,0), vis(n+1,0);
	priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > MinHeap;
	dis[1] = 0;
	MinHeap.push({0,1});
	while( !MinHeap.empty() ){
		int u = MinHeap.top().second;
		MinHeap.pop();
		if( vis[u] )
			continue;
		vis[u] = 1;
		for(auto [v,w]:g[u]){
			if( dis[v] > dis[u] + w ){
				par[v] = u;
				dis[v] = dis[u] + w;
				MinHeap.push({dis[v],v});
			}
		}
	}
	if(dis[n] < 1e15){
		stack<int>path;
		int node = n;
		while( node ){
			path.push( node );
			node = par[node];
		}
		while( !path.empty() ){
			cout << path.top() <<" ";
			path.pop();
		}
		cout << endl;
		return 0;
	}
	cout << -1 << endl;
	return 0;
}


