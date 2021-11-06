#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;	

const int MOD = 1e9 + 7;
const int maxn = 2e5+10;
vector<vector<int>>g(maxn);
vector<int>vis(maxn);
vector<vector<int>>gr(maxn);
vector<int>topo;
int n,cmp,sum=0,ans=1;

void dfs1(int u=1){
	vis[u]=1;
	for(auto v:g[u]){
		if(!vis[v]){
			dfs1(v);
		}
	}
	topo.push_back(u);
}

void dfs2(int u=1){
	vis[u]=1;
	cmp++;
	for(auto v:g[u]){
		if(!vis[v]){
			dfs2(v);
		}
	}
}

int32_t main(){   
	cin>>n;
	for(int i=1;i<=n;i++){
		int u=i,v;cin>>v;
		g[u].push_back(v);
		gr[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			dfs1(i);
		}
	}
	vector<int>p2(n+1);
	p2[0]=1;
	for(int i=1;i<=n;i++){
		p2[i]=p2[i-1]*2;
		p2[i]%=MOD;
	}
	// TODO: Realise topo contaning reverse of topological sort, same solution discussed in editorial.
	//reverse(topo.begin(),topo.end());
	fill(vis.begin(),vis.end(),0);

	for(int i=0;i<n;i++){
		int u=topo[i];
		if(!vis[u]){
			cmp=0;
			dfs2(u);
			if( cmp!= 1 ){
				ans*=p2[cmp]-2+MOD;
				ans%=MOD;
				sum+=cmp;
			}
		}
	}
	ans*=p2[n-sum];
	ans%=MOD;
	cout<<ans<<endl;

}



