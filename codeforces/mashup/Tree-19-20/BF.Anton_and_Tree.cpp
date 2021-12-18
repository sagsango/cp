#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define bug1( x ) cerr << (#x) <<"="<< x << endl;
#define bug2( x , y ) cerr << (#x) <<"="<< (x) << "    " << (#y) << "="<< (y) << endl;
#define bug3( x , y , z ) cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << endl;
#define bug4( x , y , z , w) cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << endl;
#define bug5( x , y , z , w ,p) cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << "    " << (#p) <<"="<< p << endl;
#define bug6( x , y , z , w ,p , q) cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << "    " << (#p) <<"="<< p << "    " << (#q) <<"="<< q << endl;
#define bugn( x , n ){ cerr<<(#x)<<":";for(int i=0;i<n;i++)cout<<(#x)<<"["<<i<<"]:"<< x[i] << "    "; cout<<endl;}
#define bugnm( x , n , m ){ cerr<<(#x)<<endl;for(int i=0;i<n;i++){ cout<<"Row #"<<i<<":"; for(int j=0;j<m;j++) cout<<x[i][j]<<"     "; cout << endl;}}

#define __builtin_popcount __builtin_popcountll
#define sqrt sqrtl
#define cbrt cbrtl
#define pow powl

using namespace std;

typedef unsigned long long ul;
typedef long double ld;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector <vi> vvi;
typedef vector<vvi> vvvi;

/*
 * merge all same clr neighbor nodes
 * now find dia, and you will start this change clr operation from centre, to cover all node of this bipartite tree
 */
const int nax = 2e5+10;
vector<int>par(nax,-1),g[nax],clr(nax);
set<int>gm[nax];
int dp[nax],dia,n;
int root(int u){ return par[u] < 0 ? u : par[u] = root(par[u]); }
void merge(int u,int v){
	if( (u = root(u)) == (v = root(v)) ) return;
	if( par[u] > par[v] )swap(u,v);
	par[u] += par[v];
	par[v] = u;
}
void dfs(int u,int p){
	for(auto v:gm[u]){
		if( v != p ){
			dfs(v,u);
			dia = max(dia,dp[u]+dp[v]+1);
			dp[u] = max(dp[u],dp[v]+1);
		}
	}
}
int32_t main(){
	IOS
	cin >> n;
	for(int i=1;i<=n;++i)
		cin >> clr[i];
	for(int i=1,u,v;i<n;++i)
		cin >> u >> v, g[u].push_back(v), g[v].push_back(u);
	for(int u=1;u<=n;++u)
		for(auto v:g[u])
			if( clr[u] == clr[v] )
				merge(u,v);
	for(int u=1;u<=n;++u)
		for(auto v:g[u])
			if( root(u) != root(v) )
				gm[root(u)].insert(root(v));
	int r = root(1);
	dfs(r,0);
	cout <<  (dia+1) / 2 << endl;
}
 
/*
 * long long or int?
 * index out of bound? 
 * Tested on own test case?corner?
 * Make more general solution.
 * Read Read Read Read ....
 */

