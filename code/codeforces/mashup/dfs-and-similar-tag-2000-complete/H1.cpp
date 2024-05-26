#include <iostream>
#include <vector>
using namespace std;

const int nax = 2e5+10;
vector<int>g[nax];
long long sub[nax], dp[nax], n, ans;

void dfs1(int u,int p){
  sub[u] = 1, dp[u] = 0;
  for(auto v:g[u]){
    if( v != p ){
      dfs1(v, u);
      sub[u] += sub[v];
      dp[u] += dp[v];
    }
  }
  dp[u] += sub[u];
}

void reroot(int p,int u){
  dp[p] -= dp[u];

  dp[p] -= sub[p];
  sub[p] -= sub[u];
  dp[p] += sub[p];

  dp[u] += dp[p];
  
  dp[u] -= sub[u];
  sub[u] += sub[p];
  dp[u] += sub[u];
}

void dfs2(int u,int p){
  ans = max(ans, dp[u]);
  for(auto v:g[u]){
    if( v != p ){
        reroot(u,v);
        dfs2(v,u);
        reroot(v,u);
    }
  }
}

int main(){
  cin >> n;
  for(int i=1;i<=n-1;++i){
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs1(1,0);
  dfs2(1,0);
  cout << ans << endl;
}
