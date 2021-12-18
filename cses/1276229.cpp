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
 
using namespace std;
typedef unsigned long long ul;
typedef long double ld;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector <vi> vvi;
typedef vector<vvi> vvvi;
 
#define f first
#define s second
 
int a[20],n,x;
ii dp[1<<20];
 
string showMask(int m){
	string s;
	for(int i=0;i<n;++i)
		s += ( m >> i & 1 ) + '0';
	return s;
}
int32_t main(){
	IOS
	cin >> n >> x;
	for(int i=0;i<n;++i)
		cin >> a[i];
	for(int m=1;m<1<<n;++m)
		dp[m] = {1e9,1e9};
	// using all subset optimization : see bit problem in same section
	for(int m=0;m<1<<n;++m){
		for(int b=0;b<n;++b){
			if( m >> b & 1 ){
				int c = dp[m^1<<b].f, w = dp[m^1<<b].s;
				if( w + a[b] <= x )
					dp[m] = min(dp[m],{c,w+a[b]});
				else
					dp[m] = min(dp[m],{c+1,a[b]});
			}
		}
	}
	//for(int i=0;i<1<<n;++i)
		//bug3(showMask(i),dp[i].f,dp[i].s);
		
	// Note always dp[1<<n - 1].s will be nonzero
	cout << dp[(1<<n)-1].f + 1 << endl;
	
}
 
/*
 * long long or int?
 * index out of bound? 
 * Tested on own test case?corner?
 * Make more general solution.
 * Read Read Read Read ....
 */
