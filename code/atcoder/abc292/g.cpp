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



const int mod = 998244353;
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


const int nax = 40+2;
int dp[nax][nax][10][10][2], n, m;
string s[nax];

/*


   dp[Ith row][Jth col][total_incr][end digit][0: equal, 1:greater] = ways


   // "There is always a way" -  No, Not in this case
*/

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		cin >> s[i];
	}

	// dp[0th row][jth col][0][d][0] = 1
	for (int d=0; d<10; ++d) {
		if (s[0][0] == '?' || s[0][0] - '0' == d) {
			dp[0][0][0][d][0] = 1;
		}
	}
	
	for (int j=1; j<m; ++j) {
		for (int prv_c_d=0; prv_c_d<10; ++prv_c_d) {
			for (int cur_d = 0; cur_d<10; ++cur_d) {
				if (s[0][j] == '?' || s[0][j] - '0' == cur_d) {
					dp[0][j][0][cur_d][0] += dp[0][j-1][0][prv_c_d][0];
				}
			}
		}
	}

	for (int i=1; i<n; ++i) {
		for (int prv_r_d=0; prv_r_d<10; ++prv_r_d) {
			for (int incr=0; incr<n; ++incr) {
				for (int cur_d=0; cur_d<10; ++cur_d) {
					if (s[i][0] == '?' || s[i][0] - '0' == cur_d) {
						if (cur_d > prv_r_d) {
							dp[i][0][incr+1][cur_d][1] += dp[i-1][0][incr][prv_r_d][0] + dp[i-1][0][incr][prv_r_d][1];
						}
						if (cur_d == prv_r_d) {
							dp[i][0][incr][cur_d][0] += dp[i-1][0][incr][prv_r_d][0] + dp[i-1][0][incr][prv_r_d][1];
						}
					}
				}
			}
		}
	}

	for (int j=1; j<m; ++j) {
		for (int i=1; i<n; ++i) {
			for (int incr=0; incr<n; ++incr) {
				for (int prv_r_digit=0; prv_r_digit<10; ++prv_r_digit) {
					for (int prv_c_digit=0; prv_c_digit<10; ++prv_c_digit) {
						int cur_d = prv_r_digit;
						dp[i][j][incr][cur_d][0] += (dp[i-1][j][incr][prv_r_digit][0] + dp[i-1][j][incr][prv_r_digit][1]) * dp[i][j-1][incr][prv_c_digit][0];
						for (++cur_d; cur_d<10; ++cur_d) {
							dp[i][j][incr+1][cur_d][1] += (dp[i-1][j][incr][prv_r_digit][0] + dp[i-1][j][incr][prv_r_digit][1]) * dp[i][j-1][incr][prv_c_digit][0];
						}
						for (cur_d=0; cur_d<10; ++cur_d) {
							dp[i][j][incr][cur_d][1] += (dp[i-1][j][incr][prv_r_digit][0] + dp[i-1][j][incr][prv_r_digit][1]) * dp[i][j-1][incr][prv_c_digit][1];
						}
					}
				}
			}
		}
	}
	
	for (int i=0; i<n; ++i){
		for (int j=0;j<m;++j) {
			for (int incr=0;incr<n;++incr) {
				for (int d=0; d<10; ++d) {
					for (int s=0; s<2; ++s) {
						if (dp[i][j][incr][d][s]) {
							bug6(i, j, incr, d, s, dp[i][j][incr][d][s]);
						}
					}
				}
			}
		}
	}
	//return 0;

	ll ans = 0;
	for (int d=0; d<10; ++d) {
		for (int s=0; s<2; ++s) {
			ans += dp[n-1][m-1][n-1][d][s];
		}
	}
	cout << ans << endl;
	bug1(ans);
	
}












































