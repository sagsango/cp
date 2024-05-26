
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
class Solution {
	const int dx[4] = {+1,-1,+0,-0};
	const int dy[4] = {+0,-0,+1,-1};
	public:
	int latestDayToCross(int n, int m, vector<vector<int>>& cells){
		int l = 0, r = cells.size()+1;
		vector<vector<int>>arr(n,vector<int>(m,+1));
		vector<vector<int>>vis(n,vector<int>(m,-1));
		auto solve=[&](int mid){

			for(int i=0;i<mid;++i){
				arr[cells[i][0]-1][cells[i][1]-1]=0;
			}

			queue<pair<int,int>>q;

			for(int j=0;j<m;++j){
				if( arr[0][j] ){
					q.push({0,j});
					vis[0][j] = mid;
				}
			}

			while( q.size() ){
				int x1 = q.front().first, y1 = q.front().second; q.pop();
				for(int k=0;k<4;++k){
					int x2 = x1 + dx[k], y2 = y1 + dy[k];
					if( x2 >= 0 && x2 < n && y2 >= 0 && y2 < m && vis[x2][y2]!=mid && arr[x2][y2]){
						vis[x2][y2] = mid;
						q.push({x2,y2});
					}
				}
			}

			for(int i=0;i<mid;++i){
				arr[cells[i][0]-1][cells[i][1]-1]=1;
			}

			for(int j=0;j<m;++j){
				if( vis[n-1][j] == mid ){
					return 1;
				}
			}

			return 0;

		};
		while( l + 1 < r ){
			int m = (l+r)>>1;
			( solve(m) ? l : r ) = m;
		}
		return l;

	}
};
int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
}

