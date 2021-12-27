
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
#define bug1( x)
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

////////////////////////////
// .......................//
// I have no fear ........//
// I have no expectation..//
// I am not happy.........//
// I am not sad...........//
// .......................//
////////////////////////////


int main(){
#define int long long
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m, q; cin >> n >> m >> q;
	vector<pair<int,int>>arr(n+m);
	for(int i=0;i<n;++i){
		cin >> arr[i].first, arr[i].second = 0;
	}
	for(int i=n;i<n+m;++i){
		cin >> arr[i].first, arr[i].second = 1;
	}	
	for(int i=0;i<n+m;++i){
		bug2(arr[i].first,arr[i].second);
	}

	sort(arr.begin(),arr.end());
	for(int i=0;i<n+m;++i){
		bug2(arr[i].first,arr[i].second);
	}

	vector<int>dp(n+m),par(n+m),cnt(n+m);
	priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >pq;
	ll sum = 0;
	for(int i=0;i<n+m;++i){
		dp[i] = arr[i].first + ( i ? dp[i-1] : 0 );
		par[i] = i;
		cnt[i] = 0;
		if( arr[i].second == 0 ){
			cnt[i] = 1, sum += arr[i].first;
			if( i + 1 < n + m ){
				pq.push( {arr[i+1].first - arr[i].first,i} );
			}
		}
	}
	std::function<int(int)> root = [&](int i){
		return par[i] == i ? i : par[i] = root(par[i]);
	};
	auto merge = [&](int i,int j){
		if( (i=root(i)) == (j=root(j)) )
			return;
		if( i > j )
			swap(i,j);
		bug3(i,j,sum);
		if( cnt[i] ){
			sum -= dp[i] - (i-cnt[i] >= 0?dp[i-cnt[i]]:0);
		}
		if( cnt[j] ){
			sum -= dp[j] - (j-cnt[j] >= 0?dp[j-cnt[j]]:0);
		}
		cnt[j]+=cnt[i];
		if( cnt[j] ){
			sum += dp[j] - (j-cnt[j] >= 0?dp[j-cnt[j]]:0);
		}
		par[i] = j;
		if( j + 1 < n + m ){
			pq.push( {arr[j+1].first - arr[j].first,j});
		}
		bug3(i,j,sum);
	};
	for(int i=0;i<n+m;++i){
		bug3(i,arr[i].first,arr[i].second);
	}
	vector<pair<int,int>>query(q);
	vector<int>ans(q);
	for(int i=0;i<q;++i){
		cin >> query[i].first, query[i].second = i;
	}
	sort(query.begin(),query.end());
	bug1(sum);
	for(int i=0;i<q;++i){
		while( pq.size() && pq.top().first <= query[i].first ){
			int k = pq.top().second;
			pq.pop();
			merge(k,k+1);
		}
		ans[query[i].second] = sum;
		bug2(query[i].second,query[i].first);
	}
	for(int i=0;i<q;++i){
		cout << ans[i] <<" ";
	}
	cout << endl;

}

