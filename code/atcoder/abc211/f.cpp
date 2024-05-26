
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

#define int long long

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

struct segment{
	int l, r, open; // open = 1 , close = -1
	bool operator<(const segment & other){
		if( l != other.l ){
			return l < other.l;
		}
		return r < other.r;
	}
};

const int nax = 2e5+10;
vector<vector<segment>>segments(nax); // all vertical segemnts at given x = index
vector<vector<pair<int,int>>>Query(nax); // query[x] = { y, index }
vector<vector<int>>y_cordinate(nax); // y_cordinate at x = index
vector<int>bit(nax);
void update(int i,int val){
	i += 1; // 1 based index 
	while( i < nax )
		bit[i] += val, i += i & -i;
}
int query(int i,int val=0){
	i += 1; // 1 based index
	while( i > 0 )
		val += bit[i], i -= i & -i;
	return val;
}
void process_polygon(vector<pair<int,int>>&corner){
	vector<int>x_cordinate;
	for(auto [x,y]:corner){
		x_cordinate.push_back(x);
		y_cordinate[x].push_back(y);
	}
	sort(x_cordinate.begin(),x_cordinate.end());
	x_cordinate.erase(unique(x_cordinate.begin(),x_cordinate.end()),x_cordinate.end());
	for(auto x:x_cordinate){
		sort(y_cordinate[x].begin(),y_cordinate[x].end());
		int m = y_cordinate[x].size();
		assert( m % 2 == 0 );
		for(int i=0;i<m;i+=2){
			int l = y_cordinate[x][i+0];
			int r = y_cordinate[x][i+1];
			int parity = query(l);
			assert( parity == 1 || parity == 0 );
			if( parity ){
				segments[x].push_back({l,r,-1});
				//bug3("-1",l,r);
				update(l+0,-1);
				update(r+1,+1);
			}else{
				segments[x].push_back({l,r,+1});
				//bug3("+1",l,r);
				update(l+0,+1);
				update(r+1,-1);
			}
		}
		y_cordinate[x].clear();
	}
	/*for(int i=1;i<=2e5+5;++i){
		if( query(i) )
			bug2(i,query(i));
		assert( query(i) == 0 );
	}*/
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
		int n; cin >> n;
		for(int i=0;i<n;++i){
			int m; cin >> m;
			vector<pair<int,int>>corner(m);
			for(int j=0;j<m;++j){
				cin >> corner[j].first >> corner[j].second;
				corner[j].first <<= 1;
				corner[j].second<<= 1;
			}
			process_polygon(corner);
		}
		int q; cin >> q;
		for(int i=0;i<q;++i){
			int x, y; cin >> x >> y;
			x = (x << 1)|1;
			y = (y << 1)|1;
			Query[x].push_back({y,i});
		}
		//return 0;
		//cout << "Hello" << endl;
		vector<int>ans(q);
		fill(bit.begin(),bit.end(),0);
		for(int x=0;x<=2e5+5;++x){
			//sort(query[x].begin(),query[x].end());
			//sort(segments[x].begin(),segments[x].end());
			//int i = 0, m = segments[x].size();
			for(auto [l,r,val]:segments[x]){
				update(l+0,+val);
				update(r+1,-val);
			}
			for(auto [y,idx]:Query[x]){
				ans[idx] = query(y);
			}
		}
		for(int i=0;i<q;++i){
			cout << ans[i] <<" ";
		}
		cout << endl;





}

