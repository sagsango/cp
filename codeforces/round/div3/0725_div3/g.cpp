
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
#define bug1( x )                   { cerr << (#x) <<"="<< x << endl; }
#define bug2( x , y )               { cerr << (#x) <<"="<< (x) << "    " << (#y) << "="<< (y) << endl; }
#define bug3( x , y , z )           { cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << endl; }
#define bug4( x , y , z , w)        { cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << endl; }
#define bug5( x , y , z , w ,p)     { cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << "    " << (#p) <<"="<< p << endl; }
#define bug6( x , y , z , w ,p , q) { cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << "    " << (#p) <<"="<< p << "    " << (#q) <<"="<< q << endl; }
#define bugn( x , n )               { cerr<<(#x)<<":";for(int i=0;i<n;i++)cout<<(#x)<<"["<<i<<"]:"<< x[i] << "    "; cout<<endl; }
#define bugnm( x , n , m )          { cerr<<(#x)<<endl;for(int i=0;i<n;i++){ cout<<"Row #"<<i<<":"; for(int j=0;j<m;j++) cout<<x[i][j]<<"     "; cout << endl;} }
typedef unsigned long long ul;
typedef long double ld;
typedef long long ll;
using namespace std;

template<typename T, typename K>
inline bool smax(T &x,const K &y){ return x < y ? x = y, true : false; }
template<typename T, typename K>
inline bool smin(T &x,const K &y){ return x > y ? x = y, true : false; }

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


bool solve(ll n, ll x, ll y, ll a, ll b){
	// k * a + ( n - k ) * b <= x
	// k * b + ( n - k ) * a <= y

	// k * a - k * b <= x - n * b
	// k * b - k * a <= y - n * a

	// k * ( a - b ) <= ( x - n * b )
	// k * ( b - a ) <= ( y - n * a )
	

	// a >= b 

	// k <= ( x - n * b ) / ( a - b )
	// k >= ( x - n * b ) / ( b - a )

	// k <= ( y - n * a ) / ( b - a )
	// k >= ( y - n * a ) / ( a - b )



	if( a == b ){
		return min(x,y)/a >= n;
	}

	if( a < b )
		swap(a,b);

	if( x < n * b || y > n * a )
		return 0;

	
	ll r = min( (x-n*b)/(a-b), (y-n*a)/(b-a) );
	ll l = max( (x-n*b + (a-b-1))/(b-a), (y-n*a+(a-b-1))/(a-b));
	
	return max(l,0ll) <= min(r,n);
}



int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while( t-- ){
		long long x, y, a, b; cin >> x >> y >> a >> b;
		ll l = 0, r = 1e9+1;
		while( l +1 < r ){
			ll m = (l+r)>>1;
			( solve(m,x,y,a,b) || solve(m,y,x,a,b) ? l : r ) = m;
		}
		cout << l << endl;
	}
}

