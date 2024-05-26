#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long
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

using namespace std;

typedef unsigned long long ul;
typedef long double ld;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector <vi> vvi;
typedef vector<vvi> vvvi;
 

// O(n*m) + no of gcd calls , precomputer gcd O(1)
int a[5200][5200],n;
int32_t main(){
	IOS
	cin >> n;
	for(int i=0;i<n;++i){
		string s;cin>>s;
		for(int j=0;j<n;j+=4){
			int x = ( s[j>>2] <= '9' ? s[j>>2] - '0' : s[j>>2] - 'A' + 10 );
			for(int k=0;k<4;++k)
				a[i][j+3-k] = x >> k & 1;
		}
	}
	int g = n;
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			int k = j;
			while( k < n && a[i][j] == a[i][k])
				++k;
			g = __gcd(g,k-j);
			j = k -1;
		}
	}
	for(int j=0;j<n;++j){
		for(int i=0;i<n;++i){
			int k = i;
			while( k < n && a[i][j] == a[k][j])
				++k;
			g = __gcd(g,k-i);
			i = k - 1;
		}
	}
	cout << g << endl;
}

/*
 * long long or int?
 * index out of bound? 
 * Tested on own test case?corner?
 * Make more general solution.
 * Read Read Read Read ....
 */

