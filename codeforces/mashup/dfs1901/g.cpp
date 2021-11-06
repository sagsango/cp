#include<bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;	
		
const int maxn = 1e5 + 10;
vector<pair<int,int>>g[maxn];
vector<int>dp(maxn);
int maxsum =0 , sum =0;




		
void dfs(int u=1,int p=0,int ws=0){
	for(auto it:g[u]){
		int v = it.first;
		int w = it.second;
		if( v!=p ){
			dfs(v,u,ws+w);
		}
	}
	// TODO: No need to check for leaf, just update maxsum, it will automatically adjust, because there rae no negative edges.
	if( g[u].size() == 1 ){ //  && !p
		maxsum = max( maxsum , ws);
	}
}

int32_t main()
{   
	IOS
	int n;cin>>n;
	for(int i=1;i<n;i++){
		int u,v,w;cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
		sum+=2*w;
	}
	dfs();
	cout << sum - maxsum  << endl;
	
}



