#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
const int nax = 2e3+1;
#define ROW (1<<0) 
#define COL (1<<1) 
#define NON (0<<0)
#define INF (1LL<<50)
ll dp[nax][nax][2][2][2], arr[nax][nax], cost[3][nax]; // dp[row][col][clr][row_fliped_or_not][col_filped_or_not] = min cost
int n, m, rmask, cmask;
string s;

void smin(ll *x, ll y){
  if( *x > y){
    *x = y;
  }
}

int main(){

  cin >> n >> m;
  for(int i=0;i<n;++i){
    cin >> cost[ROW][i];
  }
  for(int i=0;i<m;++i){
    cin >> cost[COL][i];
  }

  for(int i=0;i<n;++i){
    cin >> s;
    for(int j=0;j<m;++j){
      arr[i][j] = s[j] - '0';
      for(int k=0;k<2;++k){
        for(int l=0;l<2;++l){
          for(int z=0;z<2;++z){
            dp[i][j][k][l][z] = INF;
          }
        }
      }
    }
  }

  dp[0][0][arr[0][0]^0][0][0] = 0; 
  dp[0][0][arr[0][0]^1][1][0] = cost[ROW][0];
  dp[0][0][arr[0][0]^1][0][1] = cost[COL][0];
  dp[0][0][arr[0][0]^0][1][1] = cost[ROW][0] + cost[COL][0];
  for(int i=0;i<n;++i){
    for(int j=0;j<m;++j){
      for(int k=0;k<2;++k){
        for(int x=0;x<2;++x){
          for(int y=0;y<2;++y){
            if( k == (arr[i+1][j]^0^y) ) // update state only for same color
              smin(&dp[i+1][j][arr[i+1][j]^0^y][0][y], dp[i][j][k][x][y]);
            if( k == (arr[i+1][j]^1^y) ) // update state only for same color
              smin(&dp[i+1][j][arr[i+1][j]^1^y][1][y], dp[i][j][k][x][y] + cost[ROW][i+1]);
            if( k == (arr[i][j+1]^x^0) ) // update state only for same color
              smin(&dp[i][j+1][arr[i][j+1]^x^0][x][0], dp[i][j][k][x][y]);
            if( k == (arr[i][j+1]^x^1) ) // update state only for same color
              smin(&dp[i][j+1][arr[i][j+1]^x^1][x][1], dp[i][j][k][x][y] + cost[COL][j+1]);
          }
        }
      }
    }
  }

  ll ans = INF;
  for(int i=0;i<2;++i){
    for(int j=0;j<2;++j){
      for(int k=0;k<2;++k){
        smin(&ans, dp[n-1][m-1][i][j][k]);
      }
    }
  }
  cout << ans << endl;
}
