#include <iostream>
using namespace std;
const int nax = 35+5;
long long dp[nax][nax];
int n, h;
// 
// dp[ number of nodes ][ hight ] = ways
//
//
//
int main(){
  cin >> n >> h;
  for(int i=0;i<=n;++i){
    for(int j=0;j<=h;++j){
      dp[i][j] = 0;
    }
  }

  dp[0][0] = 1;
  for(int nodes = 0; nodes <= n; ++nodes){
    for(int left_nodes = 0; left_nodes < nodes; ++left_nodes){
      for(int left_hight = 0; left_hight <= left_nodes; ++left_hight){
        int right_nodes = nodes - left_nodes - 1;
        for(int right_hight = 0; right_hight <= right_nodes; ++right_hight){
          int hight = max( left_hight, right_hight) + 1;
          dp[nodes][hight] += dp[left_nodes][left_hight] * dp[right_nodes][right_hight];
        }
      }
    }
  }

  long long ways = 0;
  for(int hight = h; hight <= n; ++hight){
    ways += dp[n][hight];
  }

  cout << ways << endl;
}
