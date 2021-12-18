//
//  mod.cpp
//
//
//  Created by Sagar Singh on 17/12/20.
//
//
 
#pragma GCC target("popcnt")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
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
#define RESET   		"\033[0m"
#define RED     		"\033[31m"      			/* Red */
#define GREEN   		"\033[32m"      			/* Green */
#define YELLOW  		"\033[33m"      			/* Yellow */
#define BLUE    		"\033[34m"      			/* Blue */
#define MAGENTA 		"\033[35m"      			/* Magenta */
#define CYAN    		"\033[36m"      			/* Cyan */
#define WHITE   		"\033[37m"      			/* White */
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
#define bug1( x )                   do{ cerr << (#x) << "=" << x << endl; }WHILE_ONCE;
#define bug2( x , y )               do{ cerr << (#x) << "=" << x << "    " << (#y) << "=" << y << endl; }WHILE_ONCE;
#define bug3( x , y , z )           do{ cerr << (#x) << "=" << x << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << endl; }WHILE_ONCE;
#define bug4( x , y , z , w)        do{ cerr << (#x) << "=" << x << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << endl; }WHILE_ONCE;
#define bug5( x , y , z , w ,p)     do{ cerr << (#x) << "=" << x << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << "    " << (#p) <<"="<< p << endl; }WHILE_ONCE;
#define bug6( x , y , z , w ,p , q) do{ cerr << (#x) << "=" << x << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << "    " << (#p) <<"="<< p << "    " << (#q) <<"="<< q << endl; }WHILE_ONCE;
#define bugn( x , n )               do{ cerr << (#x) << endl; for(int i=0;i<n;i++){ cout  << x[i] << "    "; } cout << endl; }WHILE_ONCE;
#define bugnm( x , n , m )          do{ cerr << (#x) << endl; for(int i=0;i<n;i++){ for(int j=0;j<m;j++) cout << x[i][j] << "    "; } cout << endl; }WHILE_ONCE;
#else
#define bug2( x , y )               
#define bug3( x , y , z )           
#define bug4( x , y , z , w)        
#define bug5( x , y , z , w ,p)     
#define bug6( x , y , z , w ,p , q) 
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
 
typedef struct item * pitem;
struct item{
	char val;
	int pval, cnt;
	bool rev; // to reverse 
	pitem l, r;
	item(char val):val(val),pval(rand()),cnt(1),l(NULL),r(NULL),rev(false){}
};
 
inline int size(pitem t){
	return t ? t->cnt : 0;
}
 
inline void pull(pitem t){
	t->cnt = size(t->l) + size(t->r) + 1;
}
 
inline void push(pitem t){
	if( t && t->rev ){
		swap(t->l, t->r);
		t->rev ^= true;
		if( t->l ) t->l->rev ^= true;
		if( t->r ) t->r->rev ^= true;
	}
}
 
 
void merge(pitem &t, pitem l, pitem r){
	if( !l || !r )
		return void(t = l ? l : r);
	push(l), push(r);
	if( l->pval > r->pval )
		merge(l->r, l->r, r), t = l;
	else
		merge(r->l, l, r->l), t = r;
	pull(t);
}
 
void split(pitem t, pitem &l, pitem &r, int key){ 
	if( !t )
		return void( l = r = NULL );
	push(t);
	if( size(t->l)  < key ) // Node which will be at keyth index will go in right side.
		split( t->r, t->r, r, key - size(t->l) - 1), l = t;
	else
		split( t->l, l, t->l, key), r = t;
	pull(t);
}
 
void dfs(pitem t){
	if( t ){
		push(t);
		dfs(t->l);
		cout << t->val;
		dfs(t->r);
	}
}
 
int main(){	
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	pitem t = NULL;
	string s; cin >> s;
	for(int i=0;i<n;++i){
		merge(t, t, new item(s[i]));
	}
	for(int i=0;i<m;++i){
		int x, y; cin >> x >> y;
		pitem t1, t2, t3;
		split(t, t1, t2, x-1);
		split(t2, t2, t3, y-x+1);
		t2->rev ^= true;
		merge(t, t1, t2);
		merge(t, t, t3);
	}
	dfs(t);
}
 
