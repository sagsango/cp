#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int t, n, cnt = 0, prv;
int main(){
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> tmp(n);
    for (int i=0;i<n;++i) {
      cin >> tmp[i];
    }
    sort(tmp.begin(),tmp.end());
    vector<pair<int,int>> arr;
    for (int i=0,j;i<n;i+=j) {
      for (j=0; i+j < n && tmp[i+j] == tmp[i];++j) {
      }
      arr.push_back({tmp[i],j});
    }
    n = arr.size();
    cnt = 0;
    for (int i=0;i<n;++i) {
      if (i==0 ||
          arr[i-1].first + 1 != arr[i].first) {
        prv = 0;
      }
      else {
        prv = arr[i-1].second;
      }

      if (arr[i].second > prv) {
        cnt += arr[i].second - prv;
      }
    }
    cout << cnt << endl;
  }
}
