#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> g;
vector<int>order, vis;
int t, n, x, y, i, j;

void dfs(int x) {
  vis[x] = 1;
  for (auto y:g[x]) {
    if (!vis[y]) {
      dfs(y);
    }
  }
  order.push_back(x);
}

int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    g = vector<vector<int>>(n+1,vector<int>(0));
    vis = vector<int>(n+1);
    order = vector<int>(0);
    for (j=0;j<n;++j) {
      cin >> x;
      for (i=0;i<n-2;++i) {
        cin >> y;
        g[x].push_back(y);
        x = y;
      }
    }
    for (i=1;i<=n;++i) {
      if (!vis[i]) {
        dfs(i);
      }
    }
    for (i=0;i<n;++i) {
      cout << order[n-i-1] << " ";
    }
    cout << endl;
  }
}

    

    

