
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

/*
	 const int nax = 500+5, zero = 1;
	 int dp[nax][nax][3][3], vis[nax][nax][3][3];
	 char s[nax][nax];


	 dp[x][y][xmoves][ymoves]

	 dp[x][y][0][0] -> 4 adjecent moves if cell is free


	 dp[x][y][dx][dy] -> dp[x][y][+1][+1] 
	 									-> dp[x][y][+1][-1]
										-> dp[x][y][-1][+1]
										-> dp[x][y][-1][-1]
										
										with cost of breaking 4 cells


	dp[x][y][dx][dy] 

	for(int i = 0; i < 4; ++i ){
		if( DirX[i] == dx && !DirY[i] ){
			dp[x][y][dx][dy] -> dp[x][y][0][dy] with no cost
		}
		if( DirY[i] == dy && !DirX[i] ){
			dp[x][y][dx][dy] -> dp[x][y][dx][0] with no cost
		}
		if( free( cell[x+DirX[i]][y+DirY[i]] ) ){
			dp[x][y][dx][dy] -> dp[x+DirX[i]][y+DirY[i]][0][0] with no cost
		}
	}


*/




const int nax = 500+5;
const int dx[4] = {+1,-1,+0,-0};
const int dy[4] = {+0,-0,+1,-1};
const char FREE = '.';
int dp[nax][nax];
char s[nax][nax];
int n, m;

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	for(int i=0;i<nax;++i){
		for(int j=0;j<nax;++j){
			dp[i][j] = 1e9;
		}
	}
	cin >> n >> m;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			cin >> s[i][j];
		}
	}

	deque<pair<int,int>>q;
	if( s[0][0] == FREE ){
		dp[0][0] = 0;
  	q.push_back({0,0});
	}else{
		for(int i=0;i<min(n,2);++i){
			for(int j=0;j<min(m,2);++j){
				dp[i][j] = 1;
				q.push_back({i,j});
			}
		}
	}
		
	while( q.size() ){
		int x1 = q.front().first;
		int y1 = q.front().second;
		q.pop_front();
		for(int k=0;k<4;++k){
			int x2 = x1 + dx[k], y2 = y1 + dy[k];
			if( x2 >= 0 && x2 < n && y2 >= 0 && y2 < m && s[x2][y2] == FREE && dp[x2][y2] > dp[x1][y1] ){
				dp[x2][y2] = dp[x1][y1];
				q.push_front({x2,y2});
			}
		}

		for(int dx=-2;dx<=+2;++dx){
			for(int dy=-2;dy<=+2;++dy){
				if( abs(dx) + abs(dy) > 3 )
					continue;
				int x2 = x1 + dx, y2 = y1 + dy;
				if( x2 >= 0 && x2 < n && y2 >= 0 && y2 < m && dp[x2][y2] > dp[x1][y1] + 1 ){
					dp[x2][y2] = dp[x1][y1] + 1;
					q.push_back({x2,y2});
				}
			}
		}
	}
	cout << dp[n-1][m-1] << endl;
}
	

