#include <iostream>
using namespace std;
const int nax = 2e5+10;
int bit[nax], arr[nax], t, n;
long long ans;
void update(int i,int val){
  while( i < nax )
    bit[i] += val, i += i & -i;
}
int query(int i,int val=0){
  while( i > 0 )
    val += bit[i], i -= i & -i;
  return val;
}
int main(){
  cin >> t;
  while( t-- ){
    ans = 0;
    cin >> n; 
    for(int i=1;i<=n;++i){
      cin >> arr[i];
      ans += i - 1 - query(arr[i]-1);
      update(arr[i], +1);
    }
    for(int i=1;i<=n;++i){
      update(arr[i], -1);
    }
    cout << ans << endl;
  }
  return 0;
}
