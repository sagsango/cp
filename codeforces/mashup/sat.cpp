//
//  sat.cpp
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

// solution for : ( a or b) and ( c or ~k ) and ......
const int maxn = 1e5;
vector<int>g[maxn<<1],gr[maxn<<1],tpl,vis(maxn<<1),cmp(maxn<<1),sat(maxn<<1);
int n,c=0;
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
		sat[i] =  cmp[i<<1|0] <  cmp[i<<1|1] ;// ~a -> a = a
	}
	return 1;
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);


}

