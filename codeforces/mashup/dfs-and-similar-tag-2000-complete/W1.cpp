#include <iostream>
#include <vector>
using namespace std;
const int nax = 2e5+10;
vector<int>g[nax];
long long sum[nax][2], cnt[nax][2], n, ans;

void dfs1(int u,int p){
  sum[u][0] = sum[u][1] = 0, cnt[u][0] = 1, cnt[u][1] = 0;
  for(auto v:g[u]){
    if( v != p ){
      dfs1(v,u);
      for(int i=0;i<2;++i){
        sum[u][i] += sum[v][i^1] + cnt[v][i^1];
        cnt[u][i] += cnt[v][i^1];
      }
    }
  }
}

void reroot(int p,int u){
  for(int i=0;i<2;++i){
    sum[p][i] -= sum[u][i^1] + cnt[u][i^1];
    cnt[p][i] -= cnt[u][i^1];
  }
  for(int i=0;i<2;++i){
    sum[u][i] += sum[p][i^1] + cnt[p][i^1];
    cnt[u][i] += cnt[p][i^1];
  }
}

void dfs2(int u,int p){
  ans += sum[u][0]/2 + ( sum[u][1] - cnt[u][1] ) / 2 + cnt[u][1]; 
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
  cout << ans / 2 << endl;
}
