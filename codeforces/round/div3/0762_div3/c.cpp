
//
//  mat.cpp
//  
//
//  Created by Sagar Singh on 17/12/20.
//

#pragma GCC target("popcnt")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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

#ifdef LOCAL
#define WHILE_ONCE  while(false)
#define RESET           "\033[0m"
#define RED             "\033[31m"                  /* Red */
#define GREEN           "\033[32m"                  /* Green */
#define YELLOW          "\033[33m"                  /* Yellow */
#define BLUE            "\033[34m"                  /* Blue */
#define MAGENTA         "\033[35m"                  /* Magenta */
#define CYAN            "\033[36m"                  /* Cyan */
#define WHITE           "\033[37m"                  /* White */
#define BOLDBLACK   "\033[1m\033[30m"     /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"     /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"     /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"     /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"     /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"     /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"     /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"     /* Bold White */
#define cerr cerr<<RED
#define endline RESET<<endl
#define bug1( x )                   do{ cerr << (#x) << "=" << x << endline; }WHILE_ONCE;
#define bug2( x , y )               do{ cerr << (#x) << "=" << x << "    " << (#y) << "=" << y << endline; }WHILE_ONCE;
#define bug3( x , y , z )           do{ cerr << (#x) << "=" << x << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << endline; }WHILE_ONCE;
#define bug4( x , y , z , w)        do{ cerr << (#x) << "=" << x << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << endline; }WHILE_ONCE;
#define bug5( x , y , z , w ,p)     do{ cerr << (#x) << "=" << x << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << "    " << (#p) <<"="<< p << endline; }WHILE_ONCE;
#define bug6( x , y , z , w ,p , q) do{ cerr << (#x) << "=" << x << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << "    " << (#p) <<"="<< p << "    " << (#q) <<"="<< q << endline; }WHILE_ONCE;
#define bugn( x , n )               do{ cerr << (#x) << endl; for(int i=0;i<n;i++){ cout  << x[i] << "    "; } cout << endline; }WHILE_ONCE;
#define bugnm( x , n , m )          do{ cerr << (#x) << endl; for(int i=0;i<n;i++){ for(int j=0;j<m;j++) cout << x[i][j] << "    "; } cout << endline; }WHILE_ONCE;
#else
#define bug2( x , y )
#define bug3( x , y , z )
#define bug4( x , y , z , w)
#define bug5( x , y , z , w ,p)
#define bug6( x , y , z , w ,p , q)
#define bugn( x , n )
#define bugnm( x , n , m )
#endif // LOCAL

typedef unsigned long long ul;
typedef long double ld;
typedef long long ll;

typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
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
vvi mul(vvi a,vvi b){
	int n = a.size();
	vvi c(n,vi(n));
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			for(int k=0;k<n;++k){
				c[i][j] = add( c[i][j], mul( a[i][k], b[k][j] ) );
			}
		}
	}
	return c;
}
vvi binpow(vvi a,ll p){
	int n = a.size();
	vvi r(n,vi(n));
	for(int i=0;i<n;++i){
		r[i][i] = 1;
	}
	while( p ){
		if( p & 1 )
			r = mul(r,a);
		a = mul(a,a), p >>= 1;
	}
	return r;
}

vector<int>Num(long long n){
	vector<int>num;
	while( n ){
		num.push_back( n % 10 );
		n /= 10;
	}
	return num;
}

vector<int>num;
int dp[20][20];
bool dfs(int i,int j,vector<int>&a,vector<int>&s){
	if( j > s.size() )
		return 0;
	if( i >= a.size() && j == s.size() )
		return 1;
	int & ans = dp[i][j];
	if( ans != - 1){
		return ans;
	}
	ans = 0;
	for(int d=0;d<10;++d){
		num.push_back(d);
		int ad = 0;
		if( i < a.size() ){
			ad = a[i];
		}
		int sum = ad + d;
		if( sum < 10  && s[j] == sum && dfs(i+1,j+1,a,s) ){
			return ans = 1;
		}else if( j + 1 < s.size() && sum >= 10 && sum % 10 == s[j] && sum / 10 == s[j+1] && dfs(i+1,j+2,a,s) ){
			return ans = 1;
		}
		num.pop_back();
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while( t-- ){
		memset(dp,-1,sizeof(dp)), num.clear();
		long long a, s; cin >> a >> s;
		vector<int> A = Num(a);
		vector<int> S = Num(s);
		long long ans = -1, b = 1;
		if( dfs(0,0,A,S) ){
			ans = 0;
			for(int i=0;i<num.size();++i){
				ans += b * num[i];
				b *= 10;
			}
		}
		cout << ans <<" "<<  endl;
	}
}

