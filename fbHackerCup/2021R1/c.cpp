
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

struct box{
	int u, v, w;
	bool operator<(const box & other)const{
		return w > other.w;
	}
};

const int nax = 8e5+10;
vector<pair<int,int>> g[nax];
int l[nax][21], r[nax][21], dp[nax][21], w[nax], par[nax], cnt[21], n, sum, ans;
vector<box>edg(nax);

int root(int u){ return par[u] < 0 ? u : par[u] = root(par[u]); }
void merge(int u,int v){
	if( (u=root(u)) == (v=root(v)) ) return;
	if( par[u] > par[v] )swap(u,v);
	par[u] += par[v];
	par[v] = u;
}

void dfs1(int u,int p,int i){
	for(auto [v,i]:g[u]){
		if( v != p ){
			dfs1(v,u,i);
			for(int j=1;j<w[i];++j){
				dp[u][j] += dp[v][j];
				l[i][j] += dp[v][j];
			}
			for(int j=w[i];j<=20;++j){
				dp[u][w[i]] += dp[v][j];
				l[i][w[i]] += dp[v][j];
			}
			dp[u][w[i]] += 1;
			l[i][w[i]] += 1;
		}
	}
}

void dfs2(int u,int p,int i){
	if( p ){
		for(int j=1;j<w[i];++j){
			dp[p][j] -= dp[u][j];
		}
		for(int j=w[i];j<=20;++j){
			dp[p][w[i]] -= dp[u][j];
		}
		dp[p][w[i]] -= 1;

		for(int j=1;j<w[i];++j){
			dp[u][j] += dp[p][j];
			r[i][j] += dp[p][j];
		}
		for(int j=w[i];j<=20;++j){
			dp[u][w[i]] += dp[p][j];
			r[i][w[i]] += dp[p][j];
		}
		dp[u][w[i]] += 1;
		r[i][w[i]] += 1;
	}
	for(auto [v,i]:g[u]){
		if( v != p ){
			dfs2(v,u,i);
		}
	}
	if( p ){
		for(int j=1;j<w[i];++j){
			dp[u][j] -= dp[p][j];
		}
		for(int j=w[i];j<=20;++j){
			dp[u][w[i]] -= dp[p][j];
		}
		dp[u][w[i]] -= 1;

		for(int j=1;j<w[i];++j){
			dp[p][j] += dp[u][j];
		}
		for(int j=w[i];j<=20;++j){
			dp[p][w[i]] += dp[u][j];
		}
		dp[p][w[i]] += 1;
	}
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T; cin >> T;
    for(int tt=1;tt<=T;++tt){
			cin >> n;
			for(int i=1;i<=n;++i){
				for(int j=1;j<=20;++j){
					dp[i][j] = l[i][j] = r[i][j] = 0;
				}
				g[i].clear();
				par[i] = -1;
			}
			for(int i=1;i<n;++i){
				int u, v; cin >> u >> v >> w[i];
				g[u].push_back({v,i});
				g[v].push_back({u,i});
				edg[i-1] = {u,v,w[i]};
			}
			//continue;
			dfs1(1,0,0);
			dfs2(1,0,0);
			for(int i=1;i<n;++i){
				for(int j=1;j<=20;++j){
					dp[i][j] = 0;
				}
				sum = 0;
				for(int j=20;j>=1;--j){
					sum = add(sum, l[i][j]);
					dp[i][j] = add( dp[i][j], mul(r[i][j],sum) );
				}
				sum = 0;
				for(int j=20;j>=1;--j){
					sum = add(sum, r[i][j]);
					dp[i][j] = add( dp[i][j], mul(l[i][j],sum) );
				}
				for(int j=20;j>=1;--j){
					dp[i][j] = sub( dp[i][j], mul(l[i][j],r[i][j]) );
				}
				/*for(int j=1;j<=20;++j){
					if( dp[i][j] ){
						bug3(i,j,dp[i][j]);
					}
				}*/
			}

			for(int i=1;i<=20;++i){
				cnt[i] = 0;
			}
			sort(edg.begin(),edg.begin()+n-1);
			for(int i=0;i+1<n;++i){
				int u = edg[i].u;
				int v = edg[i].v;
				int w = edg[i].w;
				cnt[ w ] = add( cnt[w] , mul( -par[root(u)], -par[root(v)] ));
				merge(u,v);
			}

			sum = 0, ans = 1;
			for(int i=1;i<=20;++i){
				sum = add( sum, mul(cnt[i],i) );
			}

			for(int i=1;i<n;++i){
				int cur_sum = sum;
				for(int j=1;j<=20;++j){
					cur_sum = sub( cur_sum, mul(dp[i][j],j) );
				}
				ans = mul(ans, cur_sum);
			}

			cout << "Case #"<<tt<<": "<< ans <<endl;
    }
}


