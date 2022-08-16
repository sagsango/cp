#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
using namespace std;
const int nax = 2e5+10;
vector<int> g[nax];
int dp[nax], dep[nax], sum, d, n, t, k, sub, x, y;
void dfs(int u,int p){
  for(auto v:g[u]){
    if( v != p ){
      dep[v] = dep[u] + 1;
      dfs(v,u);
      if( dp[v] != 0 && dp[v] != sub ){
        sum += 1;
      }
      dp[u] += dp[v];
    }
  }
}
int main(){
  cin >> t;
  while( t-- ){
    cin >> n >> k;
    cin >> x >> y;
    for(int i=0;i<k;++i){
      int u; cin >> u;
      if( !dp[u] )
        dp[u] = 1, sub += 1;
    }
    for(int i=0;i<n-1;++i){
      int u, v; cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    if( !dp[x] )
      dp[x] = 1, ++sub;
    if( !dp[y] )
      dp[y] = 1, ++sub;
    dfs(x,0);
    cout << ( 2 * sum - dep[y] ) << endl;

    for(int i=1;i<=n;++i){
      g[i].clear();
      dp[i] = dep[i] = 0;
    }
    sum =  sub = 0;

  }
}


