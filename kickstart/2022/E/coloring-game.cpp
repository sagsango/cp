
//
//  mod.cpp
//
//
//  Created by Sagar Singh on 17/12/20.
//
//
//
/*
#pragma GCC target("popcnt")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
*/
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

template<typename T, typename K>
inline bool smax(T &x,K y){ return x < y ? x = y, true : false; }
template<typename T, typename K>
inline bool smin(T &x,K y){ return x > y ? x = y, true : false; }


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
int binpow(int a,ll p){
    int r = 1;
    while( p ){
        if( p & 1 )
            r = mul(r,a);
        a = mul(a,a), p >>= 1;
    }
    return r;
}

#define BOT 0
#define JHON 1
const int nax = 1e6+10;
int dp[nax][2], n;

int32_t main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int T; cin >> T;
  for(int t=1; t<=T; ++t){
    cin >> n;
    for(int i=0;i<n;++i){
      for(int j=0;j<2;++j){
        dp[i][j] = 0;
      }
    }
    for(int i=0; i<n; ++i){
      dp[i][BOT] = 1 + min( (i - 2 >= 0 ? dp[i-2][JHON] : 0), (i - 3 >= 0 ? dp[i-3][JHON] : 0) );
      dp[i][JHON] = 0 + (i -2 >= 0 ? dp[i-2][BOT] : 0 );
    }
    cout << "Case #" << t << ": " << dp[n-1][BOT] << endl;
  }
}

