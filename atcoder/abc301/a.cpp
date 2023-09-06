/*
#pragma GCC target("popcnt")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
*/

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

#ifdef LOCAL
#define WHILE_ONCE  while(false)
#define RESET           "\033[0m"
#define RED             "\033[31m"        /* Red */
#define GREEN           "\033[32m"        /* Green */
#define YELLOW          "\033[33m"        /* Yellow */
#define BLUE            "\033[34m"        /* Blue */
#define MAGENTA         "\033[35m"        /* Magenta */
#define CYAN            "\033[36m"        /* Cyan */
#define WHITE           "\033[37m"        /* White */
#define BOLDBLACK   "\033[1m\033[30m"     /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"     /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"     /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"     /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"     /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"     /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"     /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"     /* Bold White */
#define cerr cerr<<RED
#define endl RESET<<endl
#define bug1( x )                   do{ cerr << (#x) <<"="<< x << endl; }WHILE_ONCE;
#define bug2( x , y )               do{ cerr << (#x) <<"="<< x << "    " << (#y) <<"="<< (y) << endl; }WHILE_ONCE;
#define bug3( x , y , z )           do{ cerr << (#x) <<"="<< x << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << endl; }WHILE_ONCE;
#define bug4( x , y , z , w)        do{ cerr << (#x) <<"="<< x << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << endl; }WHILE_ONCE;
#define bug5( x , y , z , w ,p)     do{ cerr << (#x) <<"="<< x << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << "    " << (#p) <<"="<< p << endl; }WHILE_ONCE;
#define bug6( x , y , z , w ,p , q) do{ cerr << (#x) <<"="<< x << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << "    " << (#p) <<"="<< p << "    " << (#q) <<"="<< q << endl; }WHILE_ONCE;
#define bugn( x , n )               do{ cerr << (#x) << endl; for(int i=0;i<n;i++){ cout << x[i] << "    "; } cout << endl; }WHILE_ONCE;
#define bugnm( x , n , m )          do{ cerr << (#x) << endl; for(int i=0;i<n;i++){ for(int j=0;j<m;j++) cout << x[i][j] << "    "; } cout << endl; }WHILE_ONCE;
#else
#define bug1( x )
#define bug2( x , y )
#define bug3( x , y , z )
#define bug4( x , y , z , w )
#define bug5( x , y , z , w ,p )
#define bug6( x , y , z , w ,p , q )
#define bugn( x , n )
#define bugnm( x , n , m )
#endif // LOCAL

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

const int nax = 2e5+10;
int n, m, q;
int par[nax][20], dp[nax][20], in_time[nax], out_time[nax], timer = 0;
int A[nax], S[nax], T[nax], U[nax], V[nax], W[nax], bridge[nax];
vector <int> order;
vector <pair<int,int>> g[nax];

namespace dsu{
	int par[nax];
	int root(int u) {
		return par[u] < 0 ? u : par[u] = root(par[u]);
	}

	void merge(int u, int v) {
		if ((u = root(u)) == (v = root(v)))
			return;
		if (par[u] > par[v])
			swap(u,v);
		par[u] += par[v];
		par[v] = u;
	}
}

void dfs(int u, int p, int e) {
	cout << "Dfs" << u << endl;
	par[u][0] = p;
	dp[u][0] = e;
	in_time[u] = timer++;
	for (int i=1; i<20; ++i) {
		par[u][i] = par[par[u][i-1]][i-1];
		dp[u][i] = W[dp[u][i-1]] > W[dp[par[u][i-1]][i-1]] ?
					dp[u][i-1] : 
					dp[par[u][i-1]][i-1];
	}
	for (auto [e,v]:g[u]) {
		if (v != p) {
			dfs(v,u,e);
		}
	}
	out_time[u] = timer++;
}

bool is_ancestor(int u, int v) {
	return in_time[u] <= in_time[v] && out_time[v] <= out_time[u];
}

int lca(int u, int v) {
	if (is_ancestor(u,v))
		return u;
	if (is_ancestor(v,u))
		return v;
	for (int i = 20 - 1; i >= 0; --i) {
		if (!is_ancestor(par[u][i],v)) 
			u = par[u][i];
	}
	return par[u][0];
}

int ancestor_query(int p, int u) {
	assert(is_ancestor(p,u));
	if (p == u)
		return 0;

	int e = 0;
	for (int i = 20 - 1; i >= 0 ; --i) {
		if (!is_ancestor(par[u][i], p)) {
			if (W[e] < W[dp[u][i]])
				e = dp[u][i];
			u = dp[u][i];
		}
	}
	if (W[e] < W[dp[u][0]])
		e = dp[u][0];
	return e;
}

int query(int u, int v) {
	int p = lca(u,v);
	int e1 = ancestor_query(p, u);
	int e2 = ancestor_query(p, v);
	if (W[e1] < W[e2])
		swap(e1, e2);
	return e1;
}


int32_t main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i=1; i<=n; ++i) {
		dsu::par[i] = -1;
	}
	for (int i=1; i<=m; ++i) {
		cin >> U[i] >> V[i] >> W[i];
		order.push_back(i);
	}
	auto cmp = [&](int &e1, int &e2) {
		return W[e1] < W[e2];
	};

	sort(order.begin(), order.end(), cmp);
	for (int i = 0,j; i <m;) {
		for (j=i; j<m && W[order[i]] == W[order[j]]; ++j) {
			int r1 = dsu::root(U[order[j]]);
			int r2 = dsu::root(V[order[j]]);
			if (r1 == r2)
				continue;
			dsu::merge(r1,r2);
		}
	}

	dfs(1,0,0);

	cin >> q;
	for (int i=1; i<=q; ++i) {
		cin >> A[i] >> S[i] >> T[i];
		int e = query(S[i],T[i]);
		cout <<  "<" << e << ">" << (e == A[i] && bridge[e] == 1) << endl;
	}
}

