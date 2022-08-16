#include <stdio.h>
const int nax = 5000;
int dp[nax][nax], arr[nax], n;
int max(int a,int b){
  return a > b ? a : b;
}
int main(){
  scanf("%d",&n); 
  for(int i=0;i<n;++i){
    scanf("%d",&arr[i]);
    dp[0][i] = arr[i];
  }
  // calculate
  for(int i=1;i<n;++i){
    for(int j=0;j<n-i;++j){
      dp[i][j] = dp[i-1][j] ^ dp[i-1][j+1];
    }
  }
  // maximize
  for(int i=1;i<n;++i){
    for(int j=0;j<n-i;++j){
      dp[i][j] = max(dp[i][j], dp[i-1][j]);
      dp[i][j] = max(dp[i][j], dp[i-1][j+1]);
    }
  }
  int q; 
  scanf("%d",&q);
  while( q-- ){
    int l, r; 
    scanf("%d%d",&l,&r);
    int j = l-1;
    int i = r - l;
    printf("%d\n",dp[i][j]);
  }
}

