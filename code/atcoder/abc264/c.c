#include <stdio.h>
#include <stdbool.h>
static int n[2], m[2], arr[2][10][10], r_mask[1<<9], c_mask[1<<9], x, y;
int bit_count(int x){
  return x ? bit_count(x>>1) + (x&1) : 0;
}
bool match(int rmsk, int cmsk){
   for(int i=0,r=0;i<n[1];++i,++r){
     while( !(rmsk >> r & 1) ){
       ++r;
     }
     for(int j=0,c=0;j<m[1];++j,++c){
       while( !(cmsk >> c & 1) ){
         ++c;
       }
       if( arr[0][r][c] != arr[1][i][j] )
         return false;
     }
   }
   return true;
}
int main(){
  for(int i=0;i<2;i++){
    scanf("%d %d", &n[i], &m[i]);
    for(int j=0;j<n[i];++j){
      for(int k=0;k<m[i];++k){
        scanf("%d",&arr[i][j][k]);
      }
    }
  }
  bool ok = n[0] >= n[1] && m[0] >= m[1];
  if(ok){
    ok = false;
    for(int i=0;i<1<<n[0];++i){
      if(bit_count(i) == n[1]){
        r_mask[x++] = i;
      }
    }
    for(int i=0;i<1<<m[0];++i){
      if(bit_count(i) == m[1]){
        c_mask[y++] = i;
      }
    }
    for(int i=0;i<x;++i){
      for(int j=0;j<y;++j){
        if( match(r_mask[i],c_mask[j]) ){
          ok = true;
          break;
        }
      }
    }
  }
  printf("%s\n", ok ? "Yes" : "No");
}
  

