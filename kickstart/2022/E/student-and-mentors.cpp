
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
  int T; cin >> T;
  for(int t=1; t<=T; ++t){
      int n; cin >> n;
      multiset<int> st;
      vector<int> arr(n), ans(n);
      for(int i=0;i<n;++i){
        cin >> arr[i];
        st.insert(arr[i]);
      }
      for(int i=0; i<n;++i){
        ans[i] = -1;
        st.erase( st.find(arr[i]) );
        auto it = st.upper_bound(arr[i]*2);
        if( it != st.begin() ){
          --it;
        }
        if( it != st.end() && *it <= arr[i]*2 ){
          ans[i] = *it;
        }
        st.insert( arr[i] );
      }
      cout <<"Case #"<< t << ": ";
      for(int i=0; i<n; ++i){
        cout << ans[i] <<" ";
      }
      cout << endl;
  


  }

	
		


	

}

