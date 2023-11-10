#include <stdio.h>

int main() {
  int t; 
  scanf("%d", &t);
  while (t--) {
    int n; 
    scanf("%d", &n);
    int only_first = 0, only_sec = 0, both = 0;
    for(int i=0;i<n;++i){
      int num, first, sec;
      scanf("%d", &num);
      first = num != i + 1;
      sec = num != n - i;

      only_first += first && !sec;
      only_sec += !first && sec;
      both += first && sec;
    }
    char * ans;
    if( only_first == only_sec ){
      if( both ){
        ans = "Tie";
      }else{
        ans = "First";
      }
    }else if( only_first < only_sec ){
      ans = "First";
    }else{
      ans = "Second";
    }
    printf("%d %d %d:%s\n", only_first, only_sec, both, ans);
  }
}
