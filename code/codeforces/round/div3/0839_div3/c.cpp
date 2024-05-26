
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

int32_t main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  scanf("%d", &t);
  while (t--) {
    int k, n;
    scanf("%d %d", &k, &n);
    int prv_ele = 1, diff = 0;
    printf("%d ", prv_ele);
    for(int i=1;i<k;++i){
      // cur + k - i - 1 = last <= n
      // cur <= last + i +  1 - k
      // cur <= n + i + 1 - k

      diff += 1;
      int cur = min( prv_ele + diff, n + i + 1 - k );
      printf("%d ", cur);
      prv_ele = cur;
    }
    printf("\n");
  }
	
		


	

}

