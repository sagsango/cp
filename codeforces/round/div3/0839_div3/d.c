/* Patience */
#include <stdio.h>
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n; 
    scanf("%d", &n);
    int arr[n];
    for (int i=0;i<n;++i) {
      scanf("%d", &arr[i]);
    }
    int l = 0, r = 1e9;
    for (int i=n-2;i>=0;i--) {
      int tl, tr;
      if (arr[i] < arr[i+1]) {
        tl = 0;
        tr = arr[i] + (arr[i+1] - arr[i])/2;
      } 
      else if (arr[i] > arr[i+1]) {
        tr = 1e9;
        tl = arr[i] - (arr[i] - arr[i+1])/2;
      }
      else {
        continue;
      }
      if (l < tl) {
        l = tl;
      }
      if (r > tr) {
        r = tr;
      }
    }
    printf("%d\n", l <= r ? l : -1);
  }
}
