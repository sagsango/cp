
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

const int nax = 2e5;
vector<ll>arr(nax),tmp(nax);
int n, m, k;
ll check(int mask, int idx){
  ll  tot = 0;
  for(int i=0;i<n;++i){
    ll num = arr[i], cst = 0;
    for(int j=30;j>=idx;--j){
      if( mask >> j & 1 ){
        int num_mask = num & ((1<<(j+1)) - 1);
        if( num_mask >> j & 1 ){
          cst += 0;
        }else{
          cst += (1<<j) - num_mask;
          num += (1<<j) - num_mask;
        }
      }
    }
    tmp[i] = cst;
  }
  sort(tmp.begin(),tmp.begin()+n);

  for(int i=0;i<k;++i){
    tot += tmp[i];
  }
  return tot;
}
        

int32_t main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> k;
  for(int i=0;i<n;++i){
    cin >> arr[i];
  }
  int mask = 0;
  for(int i=30;i>=0;--i){
    mask ^= 1 << i;
    ll cost = check(mask,i);
    if( cost > m ){
     mask ^= 1 << i;
    }
  }
  cout << mask << endl;
}
