
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


const int mod = 998244353;
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


const int nax = 3e5+10; 
static int way[nax][20], sum[nax][20], par[nax], dep[nax], n;
vector<vector<int>> g(nax);

void dfs(int u, int p, int d){
  dep[u] = d, par[u] = p;
  for(auto v:g[u]){
    dfs(v,u,d+1);
  }
}

void update(int u, int d, int new_way, int new_sum){
  int p = par[u];
  if( p ){
    int par_sum = sum[p][d+1];
    int par_way = way[p][d+1];
    int my_way  = way[u][d+0];
    //par_way -= (par_sum - my_way) * my_way;
    par_way = sub(par_way, mul(sub(par_sum,my_way),my_way));
    //par_sum -= my_way;
    par_sum = sub(par_sum, my_way);
    
    my_way = new_way;

    //par_sum += my_way;
    par_sum = add(par_sum, my_way);
    //par_way += (par_sum - my_way) * my_way;
    par_way = add(par_way, mul(sub(par_sum,my_way),my_way));

    update(p, d+1, par_way, par_sum);
  }
  sum[u][d] = new_sum;
  way[u][d] = new_way;
}

int32_t main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for(int i=2;i<=n;++i){
    int p; cin >> p;
    g[p].push_back(i);
  }
  dfs(1,0,0);
  for(int i=1;i<=n;++i){
    if( dep[i] < 20 ){
      update(i, 0, 1, 1); 
    } 
    int ways = 0;
    for(int j=0;j<20;++j){
      ways = add(ways, way[1][j]);
    }
    cout << ways << endl;
  }
}




