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

ld solve(int n){
	vector<ld>a(n+1);
	vector<ld>f(n+1);

	a[0] = 0;
	f[0] = 1;

	for(int i=1;i<=n;++i){
		f[i] = i * f[i-1];
		a[i] = i *  a[i-1] + f[i-1];
	}
	return a[n]/f[n];
}

vector<int>par;
vector<char>val;
int n, m;
int root(int u){ return par[u] < 0 ? u : par[u] = root(par[u]); }
void merge(int u,int v){
	if( (u = root(u)) == (v = root(v)) ) return;
	if( par[u] < par[v] ) swap(u,v);
	par[u] += par[v];
	par[v] = u;
}
void merge(int i,int j,int x,int y){
	merge(i*m+j,x*m+y);
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
		
		int T; cin >> T;
    for(int tt=1;tt<=T;++tt){
			cin >> n >> m;
			par = vector<int>(n*m,-1);
			val = vector<char>(n*m,'.');
			vector<vector<int>>U,D,L,R;
			U = D = L = R = vector<vector<int>>(n,vector<int>(m));
			vector<string>s(n);
			for(int i=0;i<n;++i){
				cin >> s[i];
			}

			for(int i=0;i<n;++i){
				for(int j=0;j<m;++j){
					if( s[i][j] != '#' ){
						L[i][j] = 1 + (j?L[i][j-1]:0);
					}
				}
			}

			for(int i=0;i<n;++i){
				for(int j=m-1;j>=0;--j){
					if( s[i][j] != '#' ){
						R[i][j] = 1 + (j!=m-1?R[i][j+1]:0);
					}
				}
			}

			for(int j=0;j<m;++j){
				for(int i=0;i<n;++i){
					if( s[i][j] != '#'){
						U[i][j] = 1 + (i?U[i-1][j]:0);
					}
				}
			}

			for(int j=0;j<m;++j){
				for(int i=n-1;i>=0;--i){
					if( s[i][j] != '#'){
						D[i][j] = 1 + (i!=n-1?D[i+1][j]:0);
					}
				}
			}

			for(int i=0;i<n;++i){
				for(int j=0;j<m;++j){
					if( s[i][j] != '#'){
						int l = j - L[i][j] + 1;
						int r = j + R[i][j] - 1;

						merge(i,j,i,r-(j-l));

						int u = i - U[i][j] +1;
						int d = i + D[i][j] -1;

						merge(i,j,d-(i-u),j);

						//bug6(i,j,L[i][j],R[i][j],U[i][j],D[i][j]);
						//bug6(i,j,i,r-(j-l),d-(i-u),j);
					}
				}
			}

			for(int i=0;i<n;++i){
				for(int j=0;j<m;++j){
					if( s[i][j] == '#' )
						continue;

					int r = root(i*m+j);

					if( val[r] == '.' ){
						val[r] = s[i][j];
					}
				}
			}
			int cnt = 0;
			for(int i=0;i<n;++i){
				for(int j=0;j<m;++j){
					if( s[i][j] == '#' )
						continue;

					int r = root(i*m+j);
					if( s[i][j] == '.' && val[r] != '.' ){
						++cnt;
						s[i][j] = val[r];
					}
				}
			}
			cout << "Case #"<<tt<<": "<<	cnt << endl;
			for(int i=0;i<n;++i){
				for(int j=0;j<m;++j){
					cout << s[i][j];
				}
				cout << endl;
			}
    }
}



