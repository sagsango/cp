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

// solution for : ( a or b) and ( c or ~k ) and ......
const int maxn = 2e5;
vector<int>g[maxn<<1],gr[maxn<<1],tpl,vis(maxn<<1),cmp(maxn<<1),sat(maxn<<1), par(maxn<<1,-1);
int n,c=0;

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

void dfs1(int u){
	vis[u]=1;
	for(auto v:gr[u]){
		if(!vis[v]){
			dfs1(v);
		}
	}
	tpl.push_back(u);
}
void dfs2(int u){
	cmp[u]=c;
	for(auto v:g[u]){
		if(!cmp[v]){
			dfs2(v);
		}
	}
}
// NOTE: Do not forget to pass u*2 and v*2 for making all type of edges
void add_edge(int u,int v){
	g[u].push_back(v);
	gr[v].push_back(u);
	merge(u,v);
}
void add_imp(int u,int v){ 
	add_edge(u,v);
}
void add_equi(int u,int v){
	add_imp(u,v);
	add_imp(v,u);
}
void add_or(int u,int v){ 
	// a or b = ~a -> b and ~b -> a
	add_imp(u^1,v);
	add_imp(v^1,u);
}
void add_xor(int u,int v){
	// a ^ b = ( a and ~b ) or ( ~a and b ) = ( ( a and ~b ) or ~a ) and ( ( a and ~b ) or b )) = ( ( a or ~a ) and ( ~b or ~a ) and ( a or b ) and ( ~b or b) ) = ( ~b or ~a ) and ( a or b )
	add_or(u,v);
	add_or(u^1,v^1);
}
void add_xnor(int u,int v){
	// a ⊕ b = ( a and b ) or ( ~a and ~b ) = ( (( a and b ) or ~a ) and ( ( a and b ) or ~b)  )= ( ( a or ~a ) and ( b or ~a ) and ( a or ~b ) and ( b or ~b) ) = ( b or ~a ) and ( a or ~b )
	add_or(u^1,v);
	add_or(u,v^1);
}
void add_true(int u){
	// ~a -> a = ~(~a) or a = a or a = a
	add_imp(u^1,u);
}
void add_and(int u,int v){
	add_true(u);
	add_true(v);
}
bool solve(){
	for(int i=0;i<n<<1;i++){
		if(!vis[i]){
			dfs1(i);
		}
	}
	for(int i=0;i<n<<1;i++){
		int u = tpl[2*n-i-1];
		if( !cmp[u] ){
			c++;
			dfs2(u);
		}
	}
	for(int i=0;i<n;i++){
		if( cmp[i<<1|0] == cmp[i<<1|1] ){
			return 0;
		}
		/*if (root(i<<1|0) != root(i<<1|1)) {
			sat[i] = 0; // laxicographical minimal
			continue;
		}*/
		sat[i] =  cmp[i<<1|0] <  cmp[i<<1|1] ;// ~a -> a = a 
	}
	return 1;
}


int32_t main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int q;
	cin >> n >> q;
	int a[q], b[q], o[q], ans[n];
	memset(ans, 0, sizeof(ans));
	for (int i=0; i<q; ++i) {
		cin >> a[i] >> b[i] >> o[i];
		a[i] -= 1;
		b[i] -= 1;
	}
#define MAX_BIT  30
	for (int bit=0; bit<MAX_BIT; ++bit) {
		for (int i=0; i<q; ++i) {
			int o_val = o[i] >> bit & 1;
			if (o_val) {
				add_or(a[i]<<1, b[i]<<1);
			}
			else {
				add_true((a[i]<<1)^1);
				add_true((b[i]<<1)^1);
			}
		}
		if (!solve()) {
			exit(EXIT_FAILURE);
		}
		for (int i=0; i<n; ++i) {
			ans[i] |= sat[i] << bit;
			//cout << "[" << i << "]:" << sat[i] << endl;
		}
		/*
		    85 vector<int>g[maxn<<1],gr[maxn<<1],tpl,vis(maxn<<1),cmp(maxn<<1),sat(maxn<<1), par(maxn<<1,-1);
			86 int n,c=0;
		 */
		c = 0;
		tpl.clear();
		for (int i=0; i<maxn<<1; ++i) {
			g[i].clear(), gr[i].clear();
			vis[i] = cmp[i] = sat[i] = 0;
			par[i] = -1;
		}
	}
	for (int i=0; i<n; ++i) {
		cout << ans[i] << " ";
	}
	cout << endl;
}
