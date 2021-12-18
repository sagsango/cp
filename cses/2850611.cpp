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
 
const int dx[4] = {+1,-1,+0,-0};
const int dy[4] = {+0,-0,+1,-1};
 
const int nax = 100*100*2;
int arr[nax], n, k;
 
ld ncr(int n,int r){
	if( r == 2 ){
		return 1.00 * n * ( n-1 ) / 2;
	}
	return -1;
}
 
int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
	/*
		 total possible arrays = r[1] * r[2] * r[3] * r[4] * ............ * r[n]
		 consider only i and j then ( j < i ) =>  r[1] * r[2] .. * r[j-1] * r[j+1] * ... * r[i-1] * r[i+1] * .... * r[n] * ways /  toatal array
 
		 so when you count only i and j index matters = ways / r[i] * r[j]
 
		 basic we are counting for evey i,j pair in all possible cases then dividing by total possible cases.
 
 
 
TODO:
	1. assume j < i
	2. A[j] <= A[i] then :-
		 ncr(A[j],2)
	3. A[j] > A[i] then :-
		 ( A[j] - A[i] ) * A[i] + ncr(A[i],2)
 
	 */
	cin >> n;
	for(int i=0;i<n;++i){
		cin >> arr[i];
	}
	ld exp = 0;
	for(int i=0;i<n;++i){
		for(int j=0;j<i;++j){
			if( arr[j] <= arr[i] ){
				exp += ncr(arr[j],2) / ( arr[i]*arr[j] );
			}else{
				exp += ( (arr[j]-arr[i])*arr[i] + ncr(arr[i],2) ) / ( arr[i]*arr[j] );
			}
		}
	}
	cout<<fixed<<setprecision(6)<<exp;
}
 
