#include <stdio.h>
#include <string.h>
typedef long long ll;

const int nax = 24000;
ll cst[27][27][27], x;
char str[5];
ll dp[nax][27][27], ansl, ansr;
int n, l;

void smax(ll *a, ll b){
  if( *a < b ){
    *a = b;
  }
  if( *a >= +1e17 ){
    *a = +1e17;
  }
  if( *a <= -1e17 ){
    *a = -1e17;
  }
}

int main(){

  scanf("%d", &n);
  for(int i=0;i<n;++i){
    memset(str,0,sizeof(str));
    scanf("%s %lld", str, &x);
    l = strlen(str);
    //printf("%s:%d\n" ,str, l);
    switch(l){
      case 1:
        cst[0][0][str[0]-'a'+1] += x;
        break;
      case 2:
        cst[0][str[0]-'a'+1][str[1]-'a'+1] += x;
        break;
      case 3:
        cst[str[0]-'a'+1][str[1]-'a'+1][str[2]-'a'+1] += x;
        break;
    }
  }

  ansl = ansr = -(1LL<<60);
  for(int i=0;i<nax;++i){
    for(int j=0;j<27;++j){
      for(int k=0;k<27;++k){
        dp[i][j][k] = -(1LL<<60);
      }
    }
  }


  for(int i=1;i<27;++i){
    smax(&dp[0][0][i], cst[0][0][i]);
    smax(&ansl, dp[0][0][i]);
  }
  for(int i=1;i<27;++i){
    for(int j=1;j<27;++j){
      smax(&dp[1][i][j], dp[0][0][i] + cst[0][i][j] + cst[0][0][j]);
      smax(&ansl, dp[1][i][j]);
    }
  }
  for(int i=2;i<nax;++i){
    for(int j=1;j<27;++j){
      for(int k=1;k<27;++k){
        for(int l=1;l<27;++l){
          smax(&dp[i][k][l], dp[i-1][j][k] +
                            cst[j][k][l] +
                            cst[0][k][l] +
                            cst[0][0][l]);
         if( i <= 14000 )
           smax(&ansl, dp[i][k][l]);
         else
           smax(&ansr, dp[i][k][l]);
        }
      }
    }
  }

  if( ansr > ansl ){
    printf("Infinity\n");
    return 0;
  }else{
    smax(&ansr,ansl);
    printf("%lld\n", ansr);
  }
}


