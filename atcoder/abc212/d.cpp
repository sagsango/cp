
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


template<class type>
class minqueue{
	private:
	stack<pair<type,type>>st1,st2;
	public:
	int  size()  { 	return st1.size() + st2.size();		 }
	bool empty() {	return st1.empty() & st2.empty();	 }
	type pop(){
		if( st2.empty() ){
			while( !st1.empty() ){
				type  x = st1.top().first; st1.pop();
				type  mn = st2.empty() ? x : x  < st2.top().second ? x : st2.top().second;
				st2.push({x,mn});
			}
		}
		type  x = st2.top().first; st2.pop();
		return x;
	}
	void push(type x){
		type  mn = st1.empty() ? x : x < st1.top().second ? x : st1.top().second;
		st1.push({x,mn});
	}
	type min(){
		if( st1.empty() ) return st2.top().second;
		if( st2.empty() ) return st1.top().second;
		type  x = st1.top().second < st2.top().second ? st1.top().second : st2.top().second;
		return x;
	}
};

priority_queue< ll, vector<ll>, greater<ll> >Q;
long long sum;
int i;
int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
		int q; cin >> q;
		while( q-- ){
			int t; cin >> t;
			if( t <= 2){
				int x; cin >> x;
				if( t == 1 ){
					Q.push(x-sum);
				}else{
					sum += x;
				}
			}else{
				assert( Q.size() );
				cout << Q.top() + sum  << endl;
				Q.pop();
			}
		}

		// arr[i] - prv + curr

}

