
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
#define bug2( x , y )               { cerr << (#x) <<"="<<(x) << "    " << (#y) << "="<< (y) << endl; }
#define bug3( x , y , z )           { cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << endl; }
#define bug4( x , y , z , w)        { cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << endl; }
#define bug5( x , y , z , w ,p)     { cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << "    " << (#p) <<"="<< p << endl; }
#define bug6( x , y , z , w ,p , q) { cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << "    " << (#p) <<"="<< p << "    " << (#q) <<"="<< q << endl; }
#define bugn( x , n )               { cerr<<(#x)<<":";for(int i=0;i<n;i++)cout << x[i] << " "; cout<<endl; }
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


vector<int>number(ll n){
	vector<int>num(20);
	for(int i=0;i<20;++i){
		num[20-i-1] = n % 10;
		n /= 10;
	}
	return num;
}

//dp[ len ][ first digit ][ last digit ][ less(0) or equal(1) ] = ways
ll dp[22][10][10][2];
ll count(vector<int>num){
	for(int i=0;i<22;++i){
		for(int j=0;j<10;++j){
			for(int k=0;k<10;++k){
				for(int l=0;l<2;++l){
					dp[i][j][k][l] = 0;
				}
			}
		}
	}
	dp[0][0][0][1] = 1;
	for(int i=0;i<20;++i){
		for(int j=0;j<10;++j){
			for(int k=0;k<10;++k){
				int d = 0;
				for(d=0;d<num[i];++d){
					dp[i+1][(j?j:d)][d][0] += dp[i][j][k][1];
				}
				if( d < 10 ){
					dp[i+1][(j?j:d)][d][1] += dp[i][j][k][1];
				}
				for(d=0;d<10;++d){
					dp[i+1][(j?j:d)][d][0] += dp[i][j][k][0];
				}
			}
		}
	}
	ll cnt = 0;
	for(int i=0;i<10;++i){
		for(int j=0;j<2;++j){
			cnt += dp[20][i][i][j];
		}
	}
	return cnt;
}

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll l, r; cin >> l >> r;
	cout << count(number(r)) - count(number(l-1)) << endl;
}

