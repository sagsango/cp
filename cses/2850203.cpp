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
#define bug2( x , y )               { cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << endl; }
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
 
#define CONST_MOD	( 1000'000'000 + 7 )
 
const int mod = CONST_MOD;
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
 
ld dp[105][8][8], ans[8][8];
int k;
 
const int dx[4] = {+1,-1,+0,-0};
const int dy[4] = {+0,-0,+1,-1};
 
int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	for(int i=0;i<8;++i){
		for(int j=0;j<8;++j){
			ans[i][j] = 1;
		}
	}
	int n; cin >> n;
	for(int i=0;i<8;++i){
		for(int j=0;j<8;++j){
 
			for(int p=0;p<=n;++p){
				for(int x=0;x<8;++x){
					for(int y=0;y<8;++y){
						dp[p][x][y] = 0;
					}
				}
			}
 
			dp[0][i][j] = 1;
			for(int p=0;p<n;++p){
				for(int x=0;x<8;++x){
					for(int y=0;y<8;++y){
						int dir = 0;
						for(int z=0;z<4;++z){
							int x1 = x + dx[z], y1 = y + dy[z];
							if( x1 >= 0 && x1 < 8 && y1 >= 0 && y1 < 8 ){
								++dir;
							}
						}
						for(int z=0;z<4;++z){
							int x1 = x + dx[z], y1 = y + dy[z];
							if( x1 >= 0 && x1 < 8 && y1 >= 0 && y1 < 8 ){
								dp[p+1][x1][y1] += dp[p][x][y] / dir;
							}
						}
					}
				}
			}
			for(int x=0;x<8;++x){
				for(int y=0;y<8;++y){
					ans[x][y] *= ( 1 - dp[n][x][y] );
				}
			}
 
		}
	}
	ld sum = 0;
	for(int i=0;i<8;++i){
		for(int j=0;j<8;++j){
			sum += ans[i][j];
		}
	}
	cout<<fixed<<setprecision(6)<<sum;
 
 
}
