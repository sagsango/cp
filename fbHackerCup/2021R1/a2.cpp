
//
//  mod.cpp
//
//
//  Created by Sagar Singh on 17/12/20.
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

#define WHILE_ONCE  while(false)
#define bug1( x )                   do{ cerr << (#x) << "=" << x << endl; }WHILE_ONCE;
#define bug2( x , y )               do{ cerr << (#x) << "=" << x << "    " << (#y) << "=" << y << endl; }WHILE_ONCE;
#define bug3( x , y , z )           do{ cerr << (#x) << "=" << x << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << endl; }WHILE_ONCE;
#define bug4( x , y , z , w)        do{ cerr << (#x) << "=" << x << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << endl; }WHILE_ONCE;
#define bug5( x , y , z , w ,p)     do{ cerr << (#x) <<    "=" << x << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << "    " << (#p) <<"="<< p << endl; }WHILE_ONCE;
#define bug6( x , y , z , w ,p , q) do{ cerr << (#x) << "=" << x << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << "    " << (#p) <<"="<< p << "    " << (#q) <<"="<< q << endl; }WHILE_ONCE;
#define bugn( x , n )               do{ cerr << (#x) << endl; for(int i=0;i<n;i++){ cout  << x[i] << "    "; } cout << endl; }WHILE_ONCE;
#define bugnm( x , n , m )          do{ cerr << (#x) << endl; for(int i=0;i<n;i++){ for(int j=0;j<m;j++) cout << x[i][j] << "    "; } cout << endl; }WHILE_ONCE;

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

const int nax = 8e5+10;
int prv_X[nax], prv_O[nax];
string s;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T; cin >> T;
    for(int tt=1;tt<=T;++tt){
			int n;cin >> n;
			cin >> s;
			int len = 1, prv_sum = 0, ans = 0;
			char prv = 'F';

			//int prv_X[n], prv_O[n];
			prv_X[0] = s[0] == 'X' ? 0 : -1;
			prv_O[0] = s[0] == 'O' ? 0 : -1;
			for(int i=1;i<n;++i){
				prv_X[i] = prv_X[i-1];
				prv_O[i] = prv_O[i-1];

				if( s[i] == 'O' )
					prv_O[i] = i;

				if( s[i] == 'X' )
					prv_X[i] = i;
			}
			for(int i=0;i<n;++i){
				if( s[i] == 'F' ){
					// do nothing
				}else{
					if( ( prv == 'X' && s[i] == 'O' ) || ( prv == 'O' && s[i] == 'X' ) ){
						++len;
						int k = 0;
						if( s[i] == 'O' ){
							k = i - prv_X[i] -1;
						}
						if( s[i] == 'X' ){
							k = i - prv_O[i] -1;
						}
						prv_sum = add(prv_sum,k);
					}
					prv = s[i];
				}
				//cout << len << endl;
			
				ans = add(ans, sub(mul(len,i),prv_sum));
				prv_sum = add(prv_sum, len);
				
				
			}
			cout << "Case #"<<tt<<": "<< ans <<endl;
    }
}


