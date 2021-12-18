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
 
/*
	 curr col mask to fit 11001001110010000
	 1 - means alrary filled
	 0 - means not filled already
 
	 even no of consecultive zeros
*/
 
// dp[ col ][ mask ]
int dp[1005][1<<10], n, m;
vector<int> g[1<<10];
 
int good(int cur,int nxt){
	if( cur & nxt ) 
		return 0;
	int p = 0, i = 0, msk = cur | nxt;
	while( i < n ){
		if( (msk >> i & 1) ^ 1 ){
			p ^= 1;
		}else if( p ){
			return 0;
		}
		++i;
	}
	return p == 0;
}
 
string msk(int x){
	string s;
	for(int i=0;i<n;++i){
		s += ( x >> i & 1) + '0';
	}
	return s;
}
 
int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i=0;i<1<<n;++i){
		for(int j=0;j<1<<n;++j){
			if( good(i,j)  ){
					g[i].push_back(j);
					//bug3( msk(i), msk(j|i), msk(j) );
			}
		}
	}
	dp[0][0] = 1;
	for(int i=0;i<m;++i){
		for(int j=0;j<1<<n;++j){
			for(auto k:g[j]){
				dp[i+1][k] = add(dp[i+1][k], dp[i][j]);
			}
		}
	}
	cout << dp[m][0] << endl;
}
 
