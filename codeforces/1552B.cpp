
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
#define RED             "\033[31m"        /* Red */
#define GREEN           "\033[32m"        /* Green */
#define YELLOW          "\033[33m"        /* Yellow */
#define BLUE            "\033[34m"        /* Blue */
#define MAGENTA         "\033[35m"        /* Magenta */
#define CYAN            "\033[36m"        /* Cyan */
#define WHITE           "\033[37m"        /* White */
#define BOLDBLACK   "\033[1m\033[30m"     /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"     /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"     /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"     /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"     /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"     /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"     /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"     /* Bold White */
#define cerr cerr<<RED
#define endl RESET<<endl
#define bug1( x )                   do{ cerr << (#x) <<"="<< x << endl; }WHILE_ONCE;
#define bug2( x , y )               do{ cerr << (#x) <<"="<< x << "    " << (#y) <<"="<< (y) << endl; }WHILE_ONCE;
#define bug3( x , y , z )           do{ cerr << (#x) <<"="<< x << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << endl; }WHILE_ONCE;
#define bug4( x , y , z , w)        do{ cerr << (#x) <<"="<< x << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << endl; }WHILE_ONCE;
#define bug5( x , y , z , w ,p)     do{ cerr << (#x) <<"="<< x << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << "    " << (#p) <<"="<< p << endl; }WHILE_ONCE;
#define bug6( x , y , z , w ,p , q) do{ cerr << (#x) <<"="<< x << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << "    " << (#p) <<"="<< p << "    " << (#q) <<"="<< q << endl; }WHILE_ONCE;
#define bugn( x , n )               do{ cerr << (#x) << endl; for(int i=0;i<n;i++){ cout << x[i] << "    "; } cout << endl; }WHILE_ONCE;
#define bugnm( x , n , m )          do{ cerr << (#x) << endl; for(int i=0;i<n;i++){ for(int j=0;j<m;j++) cout << x[i][j] << "    "; } cout << endl; }WHILE_ONCE;
#else
#define bug1( x )
#define bug2( x , y )
#define bug3( x , y , z )
#define bug4( x , y , z , w )
#define bug5( x , y , z , w ,p )
#define bug6( x , y , z , w ,p , q )
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

////////////////////////////
// .......................//
// I have no fear ........//
// I have no expectation..//
// I am not happy.........//
// I am not sad...........//
// .......................//
////////////////////////////

// Finding Mother Vertex, is a well known problem.
// TODO: Its celebrity problem.
int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while( t-- ){
		int n; cin >> n;
		int arr[n][5];
		for(int i=0;i<n;++i){
			for(int j=0;j<5;++j){
				cin >> arr[i][j];
			}
		}
		vector<vector<int>>mask;
		for(int m=0;m<1<<5;++m){
			if( __builtin_popcount(m) == 3 ){
				vector<int>cur_mask;
				for(int i=0;i<5;++i){
					if( m >> i & 1 ){
						cur_mask.push_back(i);
					}
				}
				mask.emplace_back(cur_mask);
			}
		}
		bug1("Hello");
		int u = 0, v = 1;
		while( v < n ){
			while( v < n ){
				bug2(u,v);
				int ok = 0;
				for(auto i:mask){
					if( arr[u][i[0]] > arr[v][i[0]] &&
							arr[u][i[1]] > arr[v][i[1]] &&
							arr[u][i[2]] > arr[v][i[2]] ){
						ok = 1;
						break;
					}
				}
				if( ok ){
					bug3("bigger",v,u);
					u = v;
					v = v + 1;
					break;
				}else{
					bug3("smaller:",v,u);
					v++;
				}
			}
		}
		bug2("last",u);
		int cnt = 0;
		for(int i=0;i<n;++i){
			if( u != i ){
				int v = i;
				for(auto i:mask){
					if( arr[u][i[0]] < arr[v][i[0]] &&
							arr[u][i[1]] < arr[v][i[1]] &&
							arr[u][i[2]] < arr[v][i[2]] ){
						cnt += 1;
						break;
					}
				}

			}
		}
		bug2(u,cnt);
		cout << ( cnt == n-1 ? u+1  : -1 ) << endl;
	}
}

