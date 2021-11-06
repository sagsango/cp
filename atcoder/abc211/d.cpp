
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
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
		int n, m; cin >> n >> m;
		vector<vector<int>>g(n+1);
		for(int i=0;i<m;++i){
			int u, v; cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		function<vector<int>(int)> bfs= [&](int s){
			vector<int>dis(n+1,1e9);
			dis[s] = 0;
			queue<int>q;
			q.push(s);
			while( q.size() ){
				int u = q.front(); q.pop();
				//bug3(s,u,dis[u]);
				for(auto v:g[u]){
					if( dis[v] > dis[u] + 1 ){
						dis[v] = dis[u] + 1;
						q.push(v);
					}
				}
			}
			return dis;
		};
		vector<int> d1 = bfs(1);
		vector<int> dn = bfs(n);

		if( d1[n] >= 1e9 ){
			cout << 0 << endl;
			return 0;
		}

		vector<int>dp(n+1),vis(n+1);
		dp[1] = 1;
		queue<int>q;
		q.push(1);
		vis[1] = 1;
		while( q.size() ){
			int u = q.front(); q.pop();
			for(auto v:g[u]){
				//bug4(u,v,d1[u] + 1 + dn[v] , d1[n]);
				if( d1[u] + 1 + dn[v] == d1[n] ){
					dp[v] = add( dp[v], dp[u] );
					if( !vis[v] ){
						vis[v] = 1;
						q.push(v);
					}

				}
			}
		}
		cout << dp[n] << endl;
}

