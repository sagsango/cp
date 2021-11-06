
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
unordered_set<int> g[nax];
int all[nax], cur[nax], subtree[nax], centroidpar[nax], n, x, nodes;
ll cnt;

void dfs(int u,int par){
	subtree[u]=1;
	nodes++;
	for(auto v:g[u]){
		if(v==par)continue;
		dfs(v,u);
		subtree[u]+=subtree[v];
	}
}


int center(int u,int par){
	for(auto v:g[u]){
		if( v == par ) continue;
		if( subtree[v] > (nodes>>1) ){
			return center(v,u);
		}
	}
	return u;
}



void dfs1(int u,int p,int h, int val){
	all[h] += val;
	for(auto v:g[u]){
		if( v != p ){
			dfs1(v,u,h+1,val);
		}
	}
}

void dfs2(int u,int p,int h, int val){
	all[h] -= val, cur[h] += val;
	for(auto v:g[u]){
		if( v != p ){
			dfs2(v,u,h+1,val);
		}
	}
}

void dfs3(int u,int p,int h){
	if( x - h >= 0 )
		cnt += all[ x - h];
	for(auto v:g[u]){
		if( v != p ){
			dfs3(v,u,h+1);
		}
	}
}



void decompose(int u=1,int par=0){

	/* find centroid of curr subtree */
	nodes=0;
	dfs(u,u);
	int c = center(u,u);
	centroidpar[c]=par;

	bug3("Before",c,cnt);
	/* solve here for curr subtree */
	for(auto v:g[c]){
		dfs1(v,c,0,+1);
	}
	for(auto v:g[c]){
		bugn(all,5);
		bugn(cur,5);

		dfs2(v,c,0,+1);

		bugn(all,5);
		bugn(cnt,5);

		dfs3(v,c,0);


		dfs2(v,c,0,-1);

		bugn(all,5);
		bugn(cnt,5);
	}
	cnt += all[ x ]; // counted onces
	for(auto v:g[c]){
		dfs1(v,c,0,-1);
	}
	bug3("After",c,cnt);

	/* Decomose recursivily and solve rest*/
	for(auto v:g[c]){
		g[v].erase(c);
		decompose(v,c);
	}
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> x;
	for(int i=0;i+1<n;++i){
		int u, v; cin >> u >> v;
		g[u].insert(v);
		g[v].insert(u);
	}
	decompose();
	cout << cnt << endl;
}

