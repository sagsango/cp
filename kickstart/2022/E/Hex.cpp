
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
#undef LOCAL
#endif

#ifdef LOCAL
#define WHILE_ONCE  while(false)
#define RESET           "\033[0m"
//#define RED             "\033[31m"        /* Red */
#define GREEN           "\033[32m"        /* Green */
#define YELLOW          "\033[33m"        /* Yellow */
//#define BLUE            "\033[34m"        /* Blue */
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
#define cerr cerr<<BOLDRED
#define endl RESET<<endl
#define bug1( x )                   do{ cerr << (#x) <<"="<< x << endl; }WHILE_ONCE;
#define bug2( x , y )               do{ cerr << (#x) <<"="<< x << "    " << (#y) <<"="<< (y) << endl; }WHILE_ONCE;
#define bug3( x , y , z )           do{ cerr << (#x) <<"="<< x << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << endl; }WHILE_ONCE;
#define bug4( x , y , z , w)        do{ cerr << (#x) <<"="<< x << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << endl; }WHILE_ONCE;
#define bug5( x , y , z , w ,p)     do{ cerr << (#x) <<"="<< x << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << "    " << (#p) <<"="<< p << endl; }WHILE_ONCE;
#define bug6( x , y , z , w ,p , q) do{ cerr << (#x) <<"="<< x << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << "    " << (#p) <<"="<< p << "    " << (#q) <<"="<< q << endl; }WHILE_ONCE;
#define bugn( x , n )               do{ cerr << (#x) << endl; for(int i=0;i<n;i++){ cout << x[i] << "    "; } cout << endl; }WHILE_ONCE;
#define bugnm( x , n , m )          do{ cerr << (#x) <<":"<< endl; for(int i=0;i<n;i++){ for(int j=0;j<m;j++) cerr << x[i][j] << "  "; cerr << endl; } cerr << endl; }WHILE_ONCE;
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

const int nax = 100, BLUE = 1, RED = 2, IMPOSSIBLE = 3;
const string ans[4] = {"Nobody wins", "Blue wins", "Red wins", "Impossible" };
char g[nax][nax];
int red[nax][nax], blue[nax][nax], vis[nax][nax], par_x[nax][nax], par_y[nax][nax], status, n, bc, rc, c, blue_w, red_w;

const int Bx[] = {-1,-1,+0,+1,+1,+0};
const int By[] = {+0,+1,+1,+0,-1,-1};
const int Rx_l[] = {+0,+1,+1,-1,-1,+0};
const int Ry_l[] = {-1,-1,+0,+0,+1,+1};
const int Rx_r[] = {+0,+1,-1,+1,-1,+0};
const int Ry_r[] = {-1,-1,+0,+0,+1,+1};

bool valid(int x,int y){
	return x >= 0 && x < n && y >= 0 && y < n;
}

void bfs(vector<pair<int,int>>s, int X_final, int Y_final, int start, int end, int step, const int dx[], const int dy[], int dp[][nax], int &t_status, char clr){
	memset(par_x,-1,sizeof(par_x)), memset(par_y,-1,sizeof(par_y)), memset(vis,-1,sizeof(vis));;
	int tx = -1, ty = -1;

	function<int(int,int)> dfs = [&](int x,int y){
		if(  ( X_final != -1 && x == X_final ) ||
				( Y_final != -1 && y == Y_final ) ){
			tx = x, ty = y;
			return vis[x][y] = 1;
		}
		if( vis[x][y] != -1 ){
			return vis[x][y];
		}
		vis[x][y] = 0;
		for(int i=start;i!=end;i+=step){
			int x1 = x + dx[i], y1 = y + dy[i];
			if( valid(x1,y1) && vis[x1][y1] == -1 && g[x1][y1] == clr ){
				par_x[x1][y1] = x, par_y[x1][y1] = y;
				if( dfs(x1,y1) ){
					return vis[x][y] = 1;
				}
			}
		}
		return vis[x][y];
	};

	for(auto &[i,j]:s){
		if( dfs(i,j) ){
			break;
		}
	}

	if( tx != -1 && ty != -1 ){
		t_status = 1 ;
		while( tx >= 0 && ty >= 0 ){
			dp[tx][ty] += 1;
			int x = par_x[tx][ty];
			int y = par_y[tx][ty];
			tx = x, ty = y;
		}
	}
}

// TODO:  can be done with flow.
// 				flow > 1 IMPOSSIBLE
// 				flow = 1 win
// 				flow = 0 
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T; cin >> T;
    for(int tt=1;tt<=T;++tt){
			cin >> n, status = 0, rc = 0, bc = 0;
			for(int i=0;i<n;++i){
				for(int j=0;j<n;++j){
					cin >> g[i][j];
					bc += g[i][j] == 'B';
					rc += g[i][j] == 'R';
				}
			}

#ifdef LOCAL
			if( tt > 42 )
				continue;
#endif

			bug2("Test case:", tt);
			bugnm(g,n,n);

			if( abs(bc-rc) > 1 ){
				status = IMPOSSIBLE;
				cout << "Case #"<<tt<<": "<< ans[status] <<endl;
				continue;
			}

			memset(blue,0,sizeof(blue)), blue_w = 0;
			vector<pair<int,int>>Bs;
			for(int i=0;i<n;++i){
				if( g[i][0] == 'B' ){
					Bs.push_back({i,0});
				}
			}
			bfs(Bs,-1,n-1,0,+6,+1,Bx,By,blue,blue_w,'B');
			bugnm(blue,n,n);
			reverse(Bs.begin(),Bs.end());
			bfs(Bs,-1,n-1,5,-1,-1,Bx,By,blue,blue_w,'B');
			bugnm(blue,n,n);



			memset(red,0,sizeof(red)), red_w = 0;
			vector<pair<int,int>>Rs;
			for(int i=0;i<n;++i){
				if( g[0][i] == 'R' ){
					Rs.push_back({0,i});
				}
			}
			bfs(Rs,n-1,-1,0,+6,+1,Rx_l,Ry_l,red,red_w,'R');
			bugnm(red,n,n);
			reverse(Rs.begin(),Rs.end());
			bfs(Rs,n-1,-1,5,-1,-1,Rx_r,Ry_r,red,red_w,'R');
			bugnm(red,n,n);


			bug4(blue_w,red_w,bc,rc);
			if( (red_w && rc < bc) || (blue_w && bc < rc) )
				status = IMPOSSIBLE;

			bc = 0, rc = 0;
			for(int i=0;i<n;++i){
				for(int j=0;j<n;++j){
					if( blue[i][j] > 1 ){
						bc = 1;
					}
					if( red[i][j] > 1 ){
						rc = 1;
					}
				}
			}

			if( ( blue_w && !bc ) || ( red_w && !rc ) || status == IMPOSSIBLE ){
				status = IMPOSSIBLE;
			}else if( blue_w ){
				status = BLUE;
			}else if( red_w ){
				status = RED;
			}


			/*
			if( !blue_w && !red_w ){
				status = 0;
			}else if( (blue_w && !bc) || ( red_w && !rc) ){
				status = IMPOSSIBLE;
			}else if( blue_w ){
				status = BLUE;
			}else if( red_w ){
				status = RED;
			}else{
				status = IMPOSSIBLE;
			}
			*/

			cout << "Case #"<<tt<<": "<< ans[status] <<endl;
    }
}


