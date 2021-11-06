
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
#define bug2( x , y )               { cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << endl; }
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

#define CONST_MOD	( 1000'000'000 + 7 )

/*
const int mod[2] = { 1e9+7, 1e9+9 };
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

const int dx[4] = {+1,-1,+0,-0};
const int dy[4] = {+0,-0,+1,-1};

const int nax = 100*100*2;
int arr[nax], n, k;

ld ncr(int n,int r){
	if( r == 2 ){
		return 1.00 * n * ( n-1 ) / 2;
	}
	return -1;
}
*/

namespace sagsango{
	class modint{
		private :
			int *num;
		public:
			modint(int num=0)	{ this->num = new int; *(this->num) = num; } 
			virtual ~modint() { delete this->num; }
		public:
			modint operator+(modint other);
			modint operator-(modint other);
			modint operator*(modint other);
			modint operator/(modint other);
			modint pow(long long p);
		protected:
			static int mod;
	};
	int modint::mod;
	modint modint::operator+(modint other){
		modint result;
		*(result.num) = *(this->num) + *(other.num);
		if( *(result.num) >= mod ){
			*(result.num) -= mod;
		}
		return result;
	}
	modint modint::operator-(modint other){
		modint result;
		*(result.num) = *(this->num) - *(other.num);
		if( *(result.num) <mod ){
			*(result.num) += mod;
		}
		return result;
	}
	modint modint::operator*(modint other){
		modint result;
		*(result.num) = (*(this->num)) * (*(other.num));
		if( *(result.num) >= mod ){
			*(result.num) %= mod;
		}
		return result;
	}
	modint modint::pow(long long p){
		modint result;
		*(result.num) = 1;
		while( p ){
			if( p & 1 )
				result = result * (*this);
			(*this) = (*this) * (*this);
		}
		return result;
	}
	modint modint::operator/(modint other){
		modint result;
		result = (*this) * other.pow(mod-2);
		return result;
	}
	class m7int:public modint{
		private:
			static int mod;
		public:
			m7int(int num=0):modint(num){	modint::mod = mod; }
			~m7int(){};
	};
	int m7int::mod = (1000'000'000 + 7);

}





	//int m7int::mod = 1e9+7;







using namespace sagsango;
int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	m7int x(100);
	m7int y(200);
	for(int i=1;i<10000;++i){
		modint z = x * y;
		y = x;
		x = z;
	}
}

