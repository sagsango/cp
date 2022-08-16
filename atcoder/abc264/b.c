#include <stdio.h>
static char atcoder[] = "atcoder";
int main(){
  int r, c;
  scanf("%d %d",&r, &c);
  if (r>8){
    r = 8 - ( r - 8 );
  }
  if (c>8){
    c = 8 - ( c - 8 );
  }
  if (r>c){
    r = c;
  }
  printf("%s\n", r & 1 ? "black" : "white");
  return 0;
}
  

