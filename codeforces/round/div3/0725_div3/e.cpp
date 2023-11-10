
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
const string haha = "haha";
int count(string s){
	int n = s.length(), cnt = 0;
	for(int i=0;i+4<=n;++i){
		int ok = 1;
		for(int j=0;j<4;++j){
			ok &= haha[j] == s[i+j];
		}
		cnt += ok;
	}
	return cnt;
}
struct box{
	ll mid;
	string s, l, r; // max length = 3
	box(){
		s = l = r = "";
		mid = 0;
	}
};
box add(box a, box b){
	box c;
	c.mid = a.mid + b.mid;
	if( ! a.s.empty() && ! b.s.empty() ){
		string tmp = a.s + b.s;
		c.mid += count(tmp);
		if( tmp.length() < 3 ){
			c.s = tmp;
		}else{
			c.l = tmp.substr(0,3);
			c.r = tmp.substr(tmp.length()-3,3);
		}
	}else if( ! a.s.empty() ){
		string tmp = a.s + b.l;
		c.mid += count(tmp);
		c.l = tmp.substr(0,3);
		c.r = b.r;
	}else if( ! b.s.empty() ){
		string tmp = a.r + b.s;
		c.mid += count(tmp);
		c.l = a.l;
		c.r = tmp.substr(tmp.length()-3,3);
	}else{
		string tmp = a.r + b.l;
		c.mid += count(tmp);
		c.l = a.l;
		c.r = b.r;
	}
	//bug4(a.mid,a.s,a.l,a.r);
	//bug4(b.mid,b.s,b.l,b.r);
	//bug4(c.mid,c.s,c.l,c.r);
	return c;
}

void find_varname(int &i, string &s, string &var){
	int n = s.length();
	while( i < n && s[i] != ' '){
		var += s[i++];
	}
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while( t-- ){
		map<string,box>var;
	  ll ans = 0;
		int n; cin >> n;
		cin.ignore();
		while( n-- ){
			string s;
			getline(cin,s);
			string var_name;
			int idx = 0;
			find_varname(idx, s, var_name);
			if( s[idx+1] == '=' ){ // addition operation
				idx += 3;
				string var1, var2;
				find_varname(idx, s, var1);
				idx += 3;
				find_varname(idx, s, var2);

				box result = add( var[var1] , var[var2] );
				var[ var_name ] = result;
				ans = result.mid;
				//bug6(var_name,var1,var2,var[var1].mid,var[var2].mid,result.mid);
			}else{ // assignment
				int idx = 0;
				string var_name;
				find_varname(idx, s, var_name);
				string str;
				idx += 4;
				find_varname(idx, s, str);

				box result;
				result.mid = count(str);
				ans = result.mid;

				if( str.length() < 3 ){
					result.s = str;
				}else{
					result.l = str.substr(0,3);
					result.r = str.substr(str.length()-3,3);
				}
				var[ var_name ] = result;
				//bug3(var_name,str,result.mid);
			}
		}
		cout << ans << endl;
	}


}

