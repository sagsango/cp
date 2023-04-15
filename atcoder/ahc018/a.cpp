//
//  mod.cpp
//
//
//  Created by Sagar Singh on 17/12/20.
//
//
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

#define COST 1
#define MAX (5000)
#define valid(x,y) (x >= 0 && x < N && y >= 0 && y < N)

const int nax = 200;
const int dx[] = {+1, -1, +0, -0};
const int dy[] = {+0, -0, +1, -1};

ll dis[nax][nax], vis[nax][nax], mn_vis[nax][nax], a[nax], b[nax], c[nax], d[nax], N, W, K, C, mn_cnt;
pair<int,int> par[nax][nax];


struct node{
	ll weight;
	ll x, y;
	bool operator< (const struct node &other) const {
		return weight > other.weight;
	}
};
priority_queue <node> pq;

void solve(int x, int y) {
	/*
C:1,P:2,cost:12918682|51
C:2,P:2,cost:13048688|86
C:4,P:2,cost:13247503|125
C:8,P:3,cost:13596681|128
C:16,P:11,cost:14156639|128
C:32,P:35,cost:14996835|128
C:64,P:83,cost:16231741|127
C:128,P:196,cost:18085348|127
*/

	int start, plus;
	switch(C) {
		case 1:
			plus = 2, start = 51;
			break;
		case 2:
			plus = 2, start = 86;
			break;
		case 4:
			plus = 2, start = 125;
			break;
		case 8:
			plus = 3, start = 128;
            break;
		case 16:
			plus = 11, start = 128;
			break;
		case 32:
			plus = 35, start = 128;
			break;
		case 64:
			plus = 83, start = 127;
			break;
		case 128:
			plus = 196, start = 127;
			break;
	}

	int p = start, r;
	do {
		cout << x <<" "<< y <<" "<< p << endl;
		cin >> r;
		p += plus; 
		if (p > MAX) {
			p = MAX;
		}
	} while (!r);

	return;
}


int32_t main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> N >> W >> K >> C;
	for (int i=0; i<W; ++i) { /* Water */
		cin >> a[i] >> b[i];
	}
	for (int i=0; i<K; ++i){ /* House */
		cin >> c[i] >> d[i];
	}

	mn_cnt = 1e9;
	for (int msk=1; msk<(1<<W); ++msk) {
		for (int i=0; i<N; ++i) {
			for (int j=0; j<N; ++j) {
				dis[i][j] = 1e18;
				par[i][j] = {-1,-1};
				vis[i][j] = 0;
			}
		}

		for (int i=0; i<W; ++i) {
			if (msk >> i & 1) {
				dis[a[i]][b[i]] = 0; 
				pq.push ({dis[a[i]][b[i]], a[i], b[i]});
			}
		}

		while (!pq.empty()) {
			struct node node = pq.top();
			pq.pop();
			for (int i=0; i<4; ++i) {
				int x = node.x + dx[i];
				int y = node.y + dy[i];
				if (valid(x,y) && dis[x][y] > node.weight + COST) {
					dis[x][y] = node.weight + COST;
					par[x][y] = {node.x, node.y};
					pq.push ({dis[x][y], x, y});
				}
			}
		}

		for (int i=0; i<K; ++i) {
			int x = c[i];
			int y = d[i];
			while( x != -1 &&
					y != -1 ) {
				vis[x][y] = 1;
				int px = par[x][y].first;
				int py = par[x][y].second;
				x = px, y = py;
			}
		}
		int cnt = 0;
		for (int i=0; i<N; ++i) {
			for (int j=0; j<N; ++j) {
				cnt += vis[i][j];
			}
		}
		if (cnt < mn_cnt) {
			mn_cnt = cnt;
			for (int i=0; i<N; ++i) {
				for (int j=0; j<N; ++j) {
					mn_vis[i][j] = vis[i][j];
				}
			}
		}
	}
	for (int i=0; i<N; ++i) {
		for (int j=0; j<N; ++j) {
			if (mn_vis[i][j]) {
				solve(i,j);
			}
		}
	}
}
