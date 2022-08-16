#include <stdio.h>
const int nax = 3e3 + 3;
long long dp[nax][2], f[nax][3], n;
// f[i th ppl][ no already fed nbr, 0, 1 or 2]
// dp[ i th ppl ][ no of fed nbr ] 
void smax(long long *a, long long b){
  if( *a < b ){
    *a = b;
  }
}
long long max(long long a, long long b){
  return a > b ? a : b;
}

int main(){
  scanf("%ld",&n);
  for(int i=0;i<3;++i){
    for(int j=0;j<n;++j){
      scanf("%ld",&f[j][i]);
    }
  }
  for(int i=0;i<n;++i){
    for(int j=0;j<2;++j){
      dp[i][j] = -1e11;
    }
  }
  dp[0][0] = f[0][0];
  for(int i=0;i+1<n;++i){
    smax(&dp[i+1][1], dp[i][1] - f[i][1] + f[i][1] + f[i+1][1]);
    smax(&dp[i+1][0], dp[i][1] - f[i][1] + f[i][2] + f[i+1][0]);
    smax(&dp[i+1][1], dp[i][0] - f[i][0] + f[i][0] + f[i+1][1]);
    smax(&dp[i+1][0], dp[i][0] - f[i][0] + f[i][1] + f[i+1][0]);
  }

  printf("%ld\n", max(dp[n-1][0],dp[n-1][1]));
}


