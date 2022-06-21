#include <iostream>
#include <vector>
using namespace std;
const int nax = 2e5+10;
vector<int> g[nax];
long long dp[nax][2], arr[nax], ans[nax], n;

void dfs(int u,int p){
  dp[u][0] = dp[u][1] = 0;
  for(auto v:g[u]){
    if( v != p ){
      dfs(v,u);
      if( dp[v][0] < dp[u][0] ){
        dp[u][0] = dp[v][0];
      }
      if( dp[v][1] > dp[u][1] ){
        dp[u][1] = dp[v][1];
      }
    }
  }
  arr[u] += -dp[u][0] - dp[u][1];
  if( arr[u] > 0 ){
    dp[u][1] += arr[u];
  }
  if( arr[u] < 0 ){
    dp[u][0] += arr[u];
  }

}


int main(){
  cin >> n;
  for(int i=1;i<=n-1;++i){
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for(int i=1;i<=n;++i){
    cin >> arr[i];
  }
  dfs(1,0);
  cout << abs(dp[1][0]) + abs(dp[1][1]) << endl;
}
