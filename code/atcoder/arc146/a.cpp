
//
//  mod.cpp
//
//
//  Created by Sagar Singh on 17/12/20.
//
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

int cmp2(string a, string b){
  if( a.length() != b.length() ){
    return a.length() > b.length();
  }
  int l = a.length();
  for(int i=0;i<l;++i){
    if( a[i] != b[i] ){
      return a[i] > b[i];
    }
  }
  return 1;
}
string bestfrom3(vector<string>arr){
  string num;
  vector<int>order = {0,1,2};
  do{

    string tmp_num = arr[order[0]] + arr[order[1]] + arr[order[2]];
    if( cmp2(tmp_num,num) == +1 ){
        num = tmp_num;
    }

  }while( next_permutation(order.begin(),order.end()) );
  return num;
}
/*
vector<string> choose3from4(vector<string>arr){
  static vector<vector<int>> ways = { {0,1,2},
                                      {0,1,3},
                                      {0,2,3},
                                      {1,2,3} };
  int best_index = 0;
  string best_num;

  for(int i=0;i<4;++i){
    string tmp_num = arr[ways[i][0]] + arr[ways[i][1]] + arr[ways[i][2]];
    if( cmp2(tmp_num, best_num) == +1 ){
      best_num = tmp_num;
      best_index = i;
    }
  }
  return {arr[ways[best_index][0]], arr[ways[best_index][1]], arr[ways[best_index][2]]};
}*/

int32_t main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n; cin >> n;
  vector<string>s(n);
  for(int i=0;i<n;++i){
    cin >> s[i];
  }
  /*
  vector<string>best = {s[0],s[1],s[2]};
  for(int i=3;i<n;++i){
    best = choose3from4({best[0],best[1],best[2],s[i]});
  }
  */
  sort(s.begin(),s.end(),cmp2);
  string max_num = bestfrom3({s[0],s[1],s[2]});
  cout << max_num << endl;

}


	
		


	



