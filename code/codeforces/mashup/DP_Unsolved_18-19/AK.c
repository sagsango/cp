#include <stdio.h>
#include <string.h>
const int nax = 5000+10;
char str[nax];
int dp[nax][nax], n, q;
int main(){
  scanf("%s",str);
  n = strlen(str);
  memset(dp,0,sizeof(dp));
  for(int i=0;i<n;++i){
    dp[i][i] = 1;
    if( i + 1 < n &&
        str[i] == str[i+1] ){
      dp[i][i+1] = 1;
    }
  }

  for(int l=3;l<=n;++l){
    for(int i=0;i+l<=n;++i){
      int j = i + l - 1;
      dp[i][j] = dp[i+1][j-1]  & ( str[i] == str[j] );
    }
  }

          
  for(int i=0;i<n;++i){
    for(int j=1;j<n;++j){
      dp[i][j] += dp[i][j-1];
    }
  }

  for(int j=0;j<n;++j){
    for(int i=n-2;i>=0;--i){
      dp[i][j] += dp[i+1][j];
    }
  }

  int q; 
  scanf("%d",&q);
  while( q-- ){
    int l, r;
    scanf("%d %d", &l, &r);
    printf("%d\n",dp[l-1][r-1]);
  }
}

  
    

