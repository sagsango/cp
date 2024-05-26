

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

#define WHILE_ONCE  while(false)
#define bug1( x )                   do{ cerr << (#x) << "=" << x << endl; }WHILE_ONCE;
#define bug2( x , y )               do{ cerr << (#x) << "=" << x << "    " << (#y) << "=" << y << endl; }WHILE_ONCE;
#define bug3( x , y , z )           do{ cerr << (#x) << "=" << x << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << endl; }WHILE_ONCE;
#define bug4( x , y , z , w)        do{ cerr << (#x) << "=" << x << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << endl; }WHILE_ONCE;
#define bug5( x , y , z , w ,p)     do{ cerr << (#x) <<    "=" << x << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << "    " << (#p) <<"="<< p << endl; }WHILE_ONCE;
#define bug6( x , y , z , w ,p , q) do{ cerr << (#x) << "=" << x << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << "    " << (#p) <<"="<< p << "    " << (#q) <<"="<< q << endl; }WHILE_ONCE;
#define bugn( x , n )               do{ cerr << (#x) << endl; for(int i=0;i<n;i++){ cout  << x[i] << "    "; } cout << endl; }WHILE_ONCE;
#define bugnm( x , n , m )          do{ cerr << (#x) << endl; for(int i=0;i<n;i++){ for(int j=0;j<m;j++) cout << x[i][j] << "    "; } cout << endl; }WHILE_ONCE;

typedef unsigned long long ul;
typedef long double ld;
typedef long long ll;
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

const int nax = 55;
vector<vector<int>>g;
int dp[nax][nax][2], tmp[nax][2], a[nax], n, m;

void dfs(int u,int p){
	dp[u][0][0] = a[u];
	for(auto v:g[u]){
		if( v != p ){
			dfs(v,u);
			for(int i=0;i<=m;++i){
				for(int j=0;j<2;++j){
					tmp[i][j] = dp[u][i][j];
				}
			}
			for(int i=0;i<=m;++i){
				for(int j=0;i+j<=m;++j){
					smax(tmp[i+j+1][0], dp[u][i][0] + dp[v][j][0] );

					smax(tmp[i+j+0][0], dp[u][i][1] + dp[v][j][0] );

					smax(tmp[i+j+0][0], dp[u][i][0] + dp[v][j][1] );

					smax(tmp[i+j-1][1], dp[u][i][1] + dp[v][j][1] );

				}
			}
			for(int i=0;i<=m;++i){
				for(int j=0;j<2;++j){
					dp[u][i][j] = tmp[i][j];
				}
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	for(int tt=1;tt<=T;++tt){
		cin >> n >> m; g = vector<vector<int>>(n+1);
		for(int i=0;i<=n;++i){
			for(int j=0;j<=m;++j){
				for(int k=0;k<2;++k){
					dp[i][j][k] = -1e9;
				}
			}
		}
		for(int i=1;i<=n;++i){
			cin >> a[i];
		}
		for(int i=1;i<n;++i){
			int u, v; cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		//continue;
		dfs(1,0);
		int ans = 0;
		for(int i=0;i<=m;++i){
			for(int j=0;j<2;++j){
				smax( ans, dp[1][i][j]);
			}
		}
		cout << "Case #"<<tt<<": "<< ans <<endl;
	}
}


