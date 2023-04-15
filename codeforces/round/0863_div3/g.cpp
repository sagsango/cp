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

const int nax = 5e3 + 10;
vector<int> clr_idx[nax];
int ncr[nax][nax], c[nax], n, k, t;
pair<int,int> dp[nax];
/*
   dp[i] = <len in multiple of k, ways>
*/

#define query(i, l, r) (upper_bound(clr_idx[i].begin(), clr_idx[i].end(), r) - \
						lower_bound(clr_idx[i].begin(), clr_idx[i].end(), l))
int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ncr[0][0] = 1;
	for (int i=1; i < nax; ++i) {
		for (int j = 0; j <= i; ++j) {
			ncr[i][j] = add( (i-1 >= 0 ? ncr[i-1][j] : 0),
					(i-1 >= 0 && j-1 >= 0 ? ncr[i-1][j-1] : 0));
		}
	}

	cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i=1; i<=n; ++i) {
			cin >> c[i];
			clr_idx[c[i]].push_back(i);
		}
	
		dp[0] = {0,1};
		for (int i=1; i<=n ;++i) {
			dp[i] = {-1,0};
		}

		for (int i=0; i<=n; ++i) {
			for (int j=i+1; j<=n; ++j) {
				int cnt = query(c[j], i+1, j);
				int len = dp[i].first + 1;
				if (cnt >= k && len >= dp[j].first) {
					if (len > dp[j].first) {
						dp[j] = {0, 0};
					}
					dp[j] = {len, add(dp[j].second,
							mul(dp[i].second, (k <= cnt ? ncr[cnt-1][k-1]: 0)))};
				}
			}
		}

		int max_len = 0, ans = 0;
		for (int i=0; i<=n; ++i) {
			if (dp[i].first > max_len) {
				max_len = dp[i].first;
			}
		}
		for (int i=0; i<=n; ++i) {
			if (dp[i].first == max_len) {
				ans = add(ans, dp[i].second);
			}
		}
		cout << ans << endl;

		for (int i=0; i<=n; ++i) {
			dp[i] = {0,0};
			c[i] = 0;
			clr_idx[i].clear();
		}
	}
}

