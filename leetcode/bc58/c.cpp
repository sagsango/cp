
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
class Solution {
public:
    inline void smin(int & a,int b){
        if( b < a )
            a = b;
    }
    int minSpaceWastedKResizing(vector<int>& a, int _k) {
        /*
        // dp[l][r][resized] = cost
        int n = a.size();
        if( _k >= n-1 )
            return 0;
        int dp[n][n][_k+1];
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                for(int k=0;k<_k+1;++k){
                    dp[i][j][k] = 1e9;
                }
            }
        }

        for(int i=0;i<n;++i){
            int mx = a[i], sum = 0;
            for(int j=i;j<n;++j){
                sum += a[j];
                mx = max(mx,a[j]);
                dp[i][j][0] = (j-i+1)*mx - sum;
            }
        }

        for(int k=1;k<=_k;++k){
            for(int l=0;l<n;++l){
                for(int r=l+1;r<n;++r){
                    for(int i=l;i+1<=r;++i){ //
                        smin(dp[l][r][k], dp[l][i][k-1] + dp[i+1][r][0]);
                        smin(dp[l][r][k], dp[l][i][0] + dp[i+1][r][k-1]);
                    }
                }
            }
        }
        return dp[0][n-1][_k];

        */

        int n = a.size();
        int cost[n][n];  // cost[l][r] = cost
        for(int i=0;i<n;++i){
            int mx = a[i], sum = 0;
            for(int j=i;j<n;++j){
                mx = max(mx, a[j]);
                sum += a[j];
                cost[i][j] = mx * (j-i+1) - sum;
            }
        }
        int dp[n][n]; // dp[till i][ no of resize ] = cost
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                dp[i][j] = 1e9;
            }
        }

        for(int i=0;i<n;++i){
            dp[i][0] = cost[0][i];
        }

        for(int i=0;i<n;++i){
            for(int j=0;j<=i;++j){
                for(int k=i+1;k<n;++k){
                    dp[k][j+1] = min(dp[k][j+1], dp[i][j] + cost[i+1][k]);
                }
            }
        }
        return dp[n-1][_k];


    }
};
int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
}

