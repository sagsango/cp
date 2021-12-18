/*
Author : sagsango
*/

#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

const int nax = 2e5+5;
vector<int>g[nax];
ll dp[nax], sub[nax], ans[nax], mx, n;

void dfs1(int u,int p){
	sub[u] = 1;
	for(auto v:g[u]){
		if( v != p ){
			dfs1(v,u);
			sub[u] += sub[v];
		}
	}
}

void dfs2(int u,int p){
	dp[u] = sub[u];
	for(auto v:g[u]){
		if( v != p ){
			dfs2(v,u);
			dp[u] += dp[v];
		}
	}
}

void dfs3(int u,int p){
	if(p){
		dp[p] -= dp[u];
		dp[p] -= sub[p];
		sub[p] -= sub[u];
		dp[p] += sub[p];

		dp[u] -= sub[u];
		sub[u] += sub[p];
		dp[u] += sub[u];
		dp[u] += dp[p];
	}
	ans[u] = dp[u];
	for(auto v:g[u]){
		if( v != p ){
			dfs3(v,u);
		}
	}
	if(p){
		dp[u] -= dp[p];
		dp[u] -= sub[u];
		sub[u] -= sub[p];
		dp[u] += sub[u];

		dp[p] -= sub[p];
		sub[p] += sub[u];
		dp[p] += sub[p];
		dp[p] += dp[u];
	}
}


int main(){
	cin>>n;
	for(int i=1;i<n;++i){
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs1(1,0);
	dfs2(1,0);
	dfs3(1,0);

	for(int i=1;i<=n;++i){
		mx = max(mx, ans[i]);
	}
	cout << mx << endl;
	
}

























int dp[nax][2], clr[nax], n;
void dfs(int u,int p){
	dp[u][clr[u]] = 1;
	for(auto v:g[u]){
		if( v != p ){
			dfs(v,u);
			dp[u][0] = dp[u][0] * ( dp[v][0] + dp[v][1] );
			dp[u][1] = dp[u][1] * ( dp[v][0] + dp[v][1] ) + dp[u][0] * ( dp[v][1] );
		}
	}
}
