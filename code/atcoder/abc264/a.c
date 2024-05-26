#include <stdio.h>
static char atcoder[] = "atcoder";
int main(){
  int l, r, i;
  scanf("%d %d",&l, &r);
  for (i=l-1; i<r; ++i)
    printf("%c",atcoder[i]);
  printf("\n");
  return 0;
}
  

