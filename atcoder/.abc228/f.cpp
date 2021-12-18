
//
//  mat.cpp
//  
//
//  Created by Sagar Singh on 17/12/20.
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
#define bugn( x , n )               do{ cerr << (#x) << endl; for(int i=0;i<n;i++){ cerr  << x[i] << "    "; } cerr << endline; }WHILE_ONCE;
#define bugnm( x , n , m )          do{ cerr << (#x) << endl; for(int i=0;i<n;i++){ for(int j=0;j<m;j++) cerr << x[i][j] << "    "; cerr << endline; } cerr << endline; }WHILE_ONCE;
#else
#define bug1( x )
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

template<class type>
class maxque{
	private:
	stack<pair<type,type>>st1,st2;
	public:
	int  size()  { 	return st1.size() + st2.size();		 }
	bool empty() {	return st1.empty() & st2.empty();	 }
	type pop(){
		if( st2.empty() ){
			while( !st1.empty() ){
				type x = st1.top().first; st1.pop();
				type mx = st2.empty() ? x : x  > st2.top().second ? x : st2.top().second;
				st2.push({x,mx});
			}
		}
		type x = st2.top().first; st2.pop();
		return x;
	}
	void push(type x){
		type mx = st1.empty() ? x : x > st1.top().second ? x : st1.top().second;
		st1.push({x,mx});
	}
	type max(){
		if( st1.empty() ) return st2.top().second;
		if( st2.empty() ) return st1.top().second;
		type x = st1.top().second > st2.top().second ? st1.top().second : st2.top().second;
		return x;
	}
};

const int nax = 1005;
int n, m, r1, c1, r2, c2; 
ll arr[nax][nax], dp[nax][nax], dp2[nax][nax], dp3[nax][nax];

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> r1 >> c1 >> r2 >> c2;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			cin >> arr[i][j];
		}
	}
	
	for(int i=1;i<n;++i){
		for(int j=0;j<m;++j){
			arr[i][j] += arr[i-1][j];
		}
	}
	for(int j=1;j<m;++j){
		for(int i=0;i<n;++i){
			arr[i][j] += arr[i][j-1];
		}
	}

	if( r1 <= r2 && c1 <= c2 )
		return cout << 0,0;

	int r = min(r1,r2), c = min(c1,c2);
	int dr = r1 - r;
	int dc = c1 - c;

	auto sum = [&](int i,int j,int r,int c){
		int x1 = i, y1 = j;
		int x2 = i + r - 1;
		int y2 = j + c - 1;
		return arr[x2][y2] - (x1?arr[x1-1][y2]:0) - (y1?arr[x2][y1-1]:0) + (x1&&y1?arr[x1-1][y1-1]:0);
	};

	for(int i=0;i+r<=n;++i){
		for(int j=0;j+c<=m;++j){
			dp[i][j] = sum(i,j,r,c);
		}
	}
	
	for(int j=0;j+c<=m;++j){
		maxque<ll>q;
		for(int i=0;i<dr;++i){
			q.push(dp[i][j]);
		}
		for(int i=dr;i+r<=n;++i){
			q.push(dp[i][j]);
			dp2[i][j] = q.max();
			q.pop();
		}
	}

	for(int i=0;i+r<=n;++i){
		maxque<ll>q;
		for(int j=0;j<dc;++j){
			q.push(dp2[i][j]);
		}
		for(int j=dc;j+c<=m;++j){
			q.push(dp2[i][j]);
			dp3[i][j] = q.max();
			q.pop();
		}
	}

	ll ans = -1e18;

	bugnm(dp,n,m);
	bugnm(dp2,n,m);
	bugnm(dp3,n,m);
	for(int i=0;i+r1<=n;++i){
		for(int j=0;j+c1<=m;++j){
			ans = max(ans, sum(i,j,r1,c1) - dp3[i+r1-r][j+c1-c] );
		}
	}
	
	cout << ans << endl;






}

