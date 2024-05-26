#include <iostream>
#include <vector>
using namespace std;
const int nax = 2e5+10;
vector<int> g[nax];
int dp[nax][2], clr[nax], ans[nax], n;

void dfs1(int u,int p){
  dp[u][clr[u]^0] = 1;
  dp[u][clr[u]^1] = 0;
  for(auto v:g[u]){
    if( v != p ){
      dfs1(v,u);
      if( dp[v][1] >= dp[v][0] ){
        dp[u][1] += dp[v][1];
        dp[u][0] += dp[v][0];
      }
    }
  }
}

void reroot(int p,int u){
  if( dp[u][1] >= dp[u][0] ){
    dp[p][1] -= dp[u][1];
    dp[p][0] -= dp[u][0];
  }
  if( dp[p][1] >= dp[p][0] ){
    dp[u][1] += dp[p][1];
    dp[u][0] += dp[p][0];
  }
}

void dfs2(int u,int p){
  ans[u] = dp[u][1] - dp[u][0];
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
  for(int i=1;i<=n;++i){
    cin >> clr[i];
  }
  for(int i=1;i<=n-1;++i){
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs1(1,0);
  dfs2(1,0);
  for(int i=1;i<=n;++i){
    cout << ans[i] <<( i == n ? "\n" : " ");
  }
}
