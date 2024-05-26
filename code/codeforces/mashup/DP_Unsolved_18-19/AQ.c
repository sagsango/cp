/*
 *
 *
 * Finds the least lucky number
 * which is not less that n.
 *
 *
 * not for SUPER LUCKY number.
 *
 *
 */
 
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
const int nax = 1e5+10;
char str[nax];
int dp[nax][2][2], num[nax], bt[nax], dig[3] = {0,4,7}, n;
// dp[ length ][ equal = 1 or greater = 0 ][ non zero ] = visited or not


bool dfs(int len, int is_equal, int non_zero ){
  if( len == n )
    return non_zero;
  int *ans = &dp[len][is_equal][non_zero];
  if( *ans != -1 )
    return *ans;
  *ans = -1;
  if( is_equal ){
    for(int i=0;i<3;++i){
      if( dig[i] <  num[len]  || ( non_zero && i ==0 ) )
        continue;
      bt[len] = dig[i];
      if( dig[i] == num[len] && ( *ans = dfs(len+1, 1, non_zero || (dig[i]!=0) ) ) == 1 )
        return *ans;
      if( dig[i] > num[len] && ( *ans = dfs(len+1, 0, non_zero || (dig[i]!=0) ) ) == 1)
        return *ans;
    }
  }
  if( !is_equal ){
    // means greater
    for(int i=0;i<3;++i){
      if( non_zero && i == 0 )
        continue;
      bt[len] = dig[i];
      if ( ( *ans = dfs(len+1, 0, non_zero || (dig[i]!=0) ) ) == 1 )
        return *ans;
    }
  }
  return *ans;
}

int main(){
  memset(dp,-1,sizeof(dp));
  scanf("%s", str+5);
  n = 5 + strlen(str+5);
  for(int i=0;i<n;++i){
    if( str[i] ){
      num[i] = str[i] - '0';
    }
  }
  for(int i = 0; i < 3; ++i){
      bt[0] = dig[i];
      if( dfs(1, 1, 0)  == 1 ){
        printf("Mia\n");
        break;
      }
  }
  int i = 0;
  while( bt[i] == 0 )
    ++i;
  while( i < n )
    printf("%d", bt[i++]);
  printf("\n");
}

