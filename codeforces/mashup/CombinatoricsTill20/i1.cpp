
//
//  allmod.cpp
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

const int mod = 1e9+7, nax = 2e5+10;
vector<int>f(nax+1),fi(nax+1),_2pow(nax+1);
inline int add(int x,int y){int z = x + y;if( z >= mod )z -= mod;return z;}
inline int sub(int x,int y){int z = x - y;if( z <  0   )z += mod;return z;}
inline int mul(int x,int y){ll z =1ll*x*y;if( z >= mod )z %= mod;return z;}
inline int ncr(int n,int r){return ( n < 0 || r < 0 || r > n ) ? 0 : mul(f[n],mul(fi[r],fi[n-r])); }
int binpow(int a,ll p){
	int r = 1;
	while( p ){
		if( p & 1 )
			r = mul(a,r);
		a = mul(a,a),p >>= 1;
	}
	return r;
}
inline int gpsum(int a,int r,int n){return r == 1 ? mul(a,n) : mul(a,mul(sub(binpow(r,n),1),binpow(sub(r,1),mod-2)));}
void compute(){
	_2pow[0]=f[0]=fi[0]=1;
	for(int i=1;i<=nax;i++){
		f[i]=mul(f[i-1],i);
		fi[i]=binpow(f[i],mod-2);
		_2pow[i] = mul(_2pow[i-1],2);
	}
}


// #1 + #2 + #3 + #4 + .... #n = n
// choose * permute
// choose = ncr(n+p-1,p-1) = ncr(n+n-1,n-1)
// permute = 2 // non increasing or non decreasing
// 1 1 1 1 1 & 2 2 2 2 & 3 3 3 .... these counted twice
// so remove n 

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	compute();
	int n; cin >> n;
	cout << sub(mul(2,ncr(n+n-1,n-1)),n) << endl;
}

