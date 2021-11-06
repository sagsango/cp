
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

const int nax = 505;
int dp[nax+nax+nax][nax*nax], n, k; // dp[ first i numbers used ][ no of inversions ] = ways.

//#define int long long

const int mod = 1e9+7;
int32_t main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> k;
	dp[0][0] = 1;
	for(int i=0;i<n;++i){
		for(int j=0;j<=k;++j){
			/*
			for(int k=0;k<=i;++k){
				dp[i+1][j+k] += dp[i][j];
				if( dp[i+1][j+k] >= mod ){
					dp[i+1][j+k] -= mod;
				}
			}
			*/
			(dp[i+1][j+0+0] += dp[i][j])%=mod;
			(dp[i+1][min(j+i+1,k+1)] += mod - dp[i][j])%=mod;
		}
		for(int j=1;j<=k;++j){
			(dp[i+1][j] +=dp[i+1][j-1])%=mod;
		}
	}
	cout << dp[n][k] << endl;

	char * a = (char*)malloc(10);
	a[0] = 'H';
	a[1] = '\0';
	cout << a[0] << endl;
				
}

