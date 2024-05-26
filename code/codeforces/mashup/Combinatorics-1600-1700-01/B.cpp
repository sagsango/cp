//
//  a.cpp
//
//
//  Created by Sagar Singh on 13/12/20.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
typedef unsigned long long ul;
typedef long double ld;
typedef long long ll;
using namespace std;

const int mod = 1e9+7;
int add(int x,int y){
    int z = x + y;
    if( z >= mod ){
        z -= mod;
    }
    return z;
}
int sub(int x,int y){
    int z = x - y;
    if( z < 0 ){
        z += mod;
    }
    return z;
}
int mul(int x,int y){
    ll z = 1ll * x * y;
    if( z >= mod ){
        z %= mod;
    }
    return z;
}
int dp[1000][10][10],n,m,ans;
// dp[i][a][r] = ways when ith index in A is having value a,
//               and ith value in B having value b.
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    memset(dp,0,sizeof(dp));
    for(int a=0;a<m;++a){
      for(int b=a;b<m;++b){
        dp[0][a][b] = 1;
      }
    }
    for(int i=0;i+1<n;++i){
      for(int a=0;a<m;++a){
        for(int b=a;b<m;++b){
          for(int a_n=a;a_n<m;++a_n){
            for(int b_n=b;b_n>=a_n;--b_n){
              dp[i+1][a_n][b_n] = add( dp[i+1][a_n][b_n], dp[i][a][b]);
            }
          }
        }
      }
    }
    ans = 0;
    for(int a=0;a<m;++a){
      for(int b=a;b<m;++b){
        ans = add(ans, dp[n-1][a][b]);
      }
    }
    cout << ans << endl;

}


