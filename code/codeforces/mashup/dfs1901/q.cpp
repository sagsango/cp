#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;	

const int maxn = 1e5+10,lgN = 20;
vector<vector<int>>g(maxn);
vector<vector<int>>up(maxn,vector<int>(lgN));
vector<int>tin(maxn);
vector<int>tout(maxn);
vector<int>h(maxn);
int n,q,timer=0;

void dfs(int u=1,int p=0){
	tin[u]=++timer;
	up[u][0]=p;
	h[u]=h[p]+1;
	for(int i=1;i<=lgN;i++){
		up[u][i]=up[ up[u][i-1] ][i-1];
	}
	for(auto v:g[u]){
		if(v!=p){
			dfs(v,u);
		}
	}
	tout[u]=++timer;
}

bool isAncester(int u,int v){
	return tin[u]<=tin[v] && tout[v]<=tout[u];
}

int lca(int u,int v){
	if( isAncester(u,v) )return u;
	if( isAncester(v,u) )return v;
	for(int i=lgN;i>=0;i--){
		if(up[u][i] && !isAncester(up[u][i],v)){
			u=up[u][i];
		}
	}
	return up[u][0];
}

int32_t main()
{   
	cin >> n >> q;
	for(int u=2;u<=n;u++){
		int v;cin>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs();
	while( q-- ){
		int ans = 0;
		vector<int>v(3);
		cin>>v[0]>>v[1]>>v[2];
		sort(v.begin(),v.end());
		do{
			int a = v[0];
			int b = v[1];
			int c = v[2];
			//  [ a & b ] - > c 
			int l = lca(a,c);
			if( lca(a,b) == lca(b,c) ){
				ans = max( ans , h[c] - h[l] +1  );
			}
			else
			{
				int l1 = lca(a,b);
				int l2 = lca(b,c);
				
				if( l1 != l ){
					ans = max( ans , h[l1]  - h[l] + h[c] - h[l] +1 );
				}
				else {
					ans = max( ans , h[c] - h[l2] + 1);
				}
			}
		}while( next_permutation( v.begin() , v.end() ) );
		cout << ans << endl;
	}
	
	
	
	
}




