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


const int nax = 500;
int par[nax], n, m, q;
string A[nax], B[nax], X[nax], Y[nax];
vector<string>arr;

int root(int u){ return par[u] < 0 ? u : par[u] = root(par[u]); }
void merge(int u,int v){
	if( (u=root(u)) == (v=root(v)) )return;
	if( par[u] > par[v] )swap(u,v);
	par[u] += par[v];
	par[v] = u;
}

#define index(s) ( lower_bound(arr.begin(),arr.end(),s) - arr.begin() )

int32_t main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while( t-- ){
		cin >> n, arr.clear();
		for(int i=0;i<n;++i){
			cin >> A[i] >> B[i];
			transform(A[i].begin(), A[i].end(), A[i].begin(), ::tolower);
			transform(B[i].begin(), B[i].end(), B[i].begin(), ::tolower);
			arr.push_back(A[i]);
			arr.push_back(B[i]);
		}
		cin >> q;
		for(int i=0;i<q;++i){
			cin >> X[i] >> Y[i];
			transform(X[i].begin(), X[i].end(), X[i].begin(), ::tolower);
			transform(Y[i].begin(), Y[i].end(), Y[i].begin(), ::tolower);
			arr.push_back(X[i]);
			arr.push_back(Y[i]);
		}
		sort(arr.begin(),arr.end());
		arr.erase(unique(arr.begin(),arr.end()),arr.end());
		m = arr.size();
		for(int i=0;i<m;++i){
			par[i] = -1;
		}
		for(int i=0;i<n;++i){
			merge(index(A[i]),index(B[i]));
		}
		for(int i=0;i<q;++i){
			if( root(index(X[i])) == root(index(Y[i])) ){
				cout << "synonyms" << endl;
			}else{
				cout << "different" << endl;
			}
		}
	}


		


	

}

