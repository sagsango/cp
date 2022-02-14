
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


struct box{
	ll item_need, offer_thresold;
	bool operator<(const box & other)const{
		if( offer_thresold != other.offer_thresold )
			return offer_thresold < other.offer_thresold;
		return item_need > other.item_need;
	}
};
const int nax = 1e5+10;
box items[nax];
ll total_items[nax], n;
int main(){
	scanf("%lld",&n);
	for(int i=0;i<n;++i){
		scanf("%lld %lld", &items[i].item_need, &items[i].offer_thresold);
	}
	std::sort(items,items+n);
	for(int i=0;i<n;++i){
		printf("need:%d, offer_threshold:%d\n",items[i].item_need, items[i].offer_thresold);
	}
	for(int i=n-1;i>=0;--i){
		total_items[i] = items[i].item_need + total_items[i+1];
	}
	ll extra_bought = std::min( items[0].offer_thresold, total_items[0]);
	ll total_bought = extra_bought;
	ll money = extra_bought * 2;
	for(int i=0;i<n;++i){
		ll already_bought_ith_items = std::max( extra_bought - total_items[i+1],  0LL);
		items[i].item_need -= already_bought_ith_items;
		extra_bought -= already_bought_ith_items;

		ll item_with_out_offer = std::min( items[i].item_need, items[i].offer_thresold - total_bought);
		ll item_with_offer = items[i].item_need - item_with_out_offer;

		bug3(total_bought, item_with_out_offer, item_with_offer);
		total_bought += items[i].item_need;
		money += item_with_out_offer  * 2 + item_with_offer * 1LL;  
	}
	printf("%lld\n",money);
}
