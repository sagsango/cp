
//
//  mod.cpp
//  
//
//  Created by Sagar Singh on 17/12/20.
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



class mint{
	private:
		int m_iVal;
	protected:
		static int mod;
	public:
		mint(int iVal=0):m_iVal(iVal){}
		~mint(){}
		mint operator+(const mint &other);
		mint operator-(const mint &other);
		mint operator*(const mint &other);
		mint operator/(const mint &other);
		void operator+=(const mint &other);
		void operator-=(const mint &other);
		void operator*=(const mint &other);
		void operator/=(const mint &other);
		void operator=(const int &other);
		void operator=(const long long &other);
		mint pow(long long p);
		int val();
};
int mint::mod = (1000'000'000 + 7);		// TODO: Take care of it.
mint mint::operator+(const mint &other){
	mint tmp;
	tmp.m_iVal = ( this->m_iVal + other.m_iVal );
	if( tmp.m_iVal >= mod ){
		tmp.m_iVal -= mod;
	}
	return tmp;
}
mint mint::operator-(const mint &other){
	mint tmp;
	tmp.m_iVal = ( this->m_iVal - other.m_iVal );
	if( tmp.m_iVal < 0 ){
		tmp.m_iVal += mod;
	}
	return tmp;
}
mint mint::operator*(const mint &other){
	long long tmp = 1ll * (this->m_iVal) * other.m_iVal;
	if( tmp >= mod ){
		tmp %= mod;
	}
	return mint((int)tmp);
}
mint mint::pow(long long p){
	mint tmp(1), a = (*this);
	while( p ){
		if( p & 1 )
			tmp = tmp * a;
		p >>= 1, a *= a;
	}
	return tmp;
}
mint mint::operator/(const mint &other){
	//return (*this) * other.pow(mod-2);
	mint tmp = other;
	return tmp.pow(mod-2) * (*this);
}
void mint::operator+=(const mint &other){
	(*this) = (*this) + other;
}
void mint::operator-=(const mint &other){
	(*this) = (*this) - other;
}
void mint::operator*=(const mint &other){
	(*this) = (*this) * other;
}
void mint::operator/=(const mint &other){
	(*this) = (*this) / other;
}
void mint::operator=(const long long &other){
	this->m_iVal = other;
}
void mint::operator=(const int &other){
	this->m_iVal = other;
}
int mint::val(){
	return this->m_iVal;
}






int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cm::mint x(2);
	x = x.pow(10);
	cout << x.val() << endl;
}

