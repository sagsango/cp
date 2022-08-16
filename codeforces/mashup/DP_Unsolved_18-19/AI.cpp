/*
 *
 * s[l] -> s[0,l]
 * s[l] -> f[0,l]
 * f[l] -> s[l+1]
 * f[l] -> f[l+1]
 *
 * s : statement
 * f : for
 * s[l] : statement at level l
 *
 *
 *
 */

#include <iostream>
using namespace std;
const int mod = 1e9+7;
const int nax = 5e3+5;

int dp[nax][nax], n;
char c;
int add(int a,int b){
  int c = a + b;
  if( c >= mod ){
    c -= mod;
  }
  return c;
}
int sub(int a,int b){
  int c = a - b;
  if( c < 0 ){
    c += mod;
  }
  return c;
}

int main(){
  cin >> n;
  dp[0][0] = 1;
  for(int i=0;i<n;++i){
    cin >> c;
    if( c == 'f' ){
      for(int j=0;j<n;++j){
        dp[i+1][j+1] = dp[i][j];
      }
    }else{
      for(int j=0;j<n;++j){
        dp[i+1][0] = add(dp[i+1][0], dp[i][j]);
        dp[i+1][j+1] = sub(dp[i+1][j+1], dp[i][j]);
      }
      for(int j=1;j<n;++j){
        dp[i+1][j] = add(dp[i+1][j], dp[i+1][j-1]);
      }
    }
  }
  int ans = 0;
  for(int i=0;i<n;++i){
    ans = add(ans, dp[n-1][i]);
  }
  cout << ans << endl;
  return 0;
}
    


