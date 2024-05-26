
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
// nax : maximum length of string
// (1e9+7)^2, (1e9+9)^2, (1e9+21)^1  <= LONG_MAX : use long long to store product
const int nx = ( 1e5 /*change len*/ )+10, M[3] ={ (int)(1e9+7), (int)(1e9+9), (int)(1e9+21) }, P[3] = {29, 31, 37};
const int hashCount = 2; // no of hashes want to use
int coef[3][nx];


int n, nax;
vector<vector<int>>ph[3],sh[3];
vector<string>s(1);

class Solution {
public:



    // n   : no of strings
    // ph  : prefix hash
    // sh  : suffix hash


    void compute(){
        // compute coef accordingly
        coef[0][0] = coef[0][1] = coef[0][2] =  1;
        for(int i=0;i<hashCount;++i){
            for(int j=1;j<nax;++j){
                coef[i][j]=1ll*coef[i][j-1]*P[i]%M[i];
            }
        }
        // initialise size of ph and sh accordingly
        for(int i=0;i<hashCount;++i){
            ph[i] = sh[i] = vector<vector<int>>(n);
            for(int j=0;j<n;++j){
                int m = s[j].size();
                ph[i][j] = sh[i][j] = vector<int>(m+2);
            }
        }
        // compute ph[0,1,2][jth string][kth index] and sh[0,1,2][jth string][kth index]
        for(int i=0;i<hashCount;++i){
            for(int j=0;j<n;++j){
                int m = s[j].size();
                for(int k=1;k<=m;++k)
                    ph[i][j][k] = (ph[i][j][k-1] + 1ll*(s[j][k-1]-'a'+1)*coef[i][k-1])%M[i];
                for(int k=m;k>=1;--k)
                    sh[i][j][k] = (sh[i][j][k+1] + 1ll*(s[j][k-1]-'a'+1)*coef[i][m-k])%M[i];
            }
        }
    }

    // s[x][l1..r1] == s[y][l2..r2]
    int equal1(int x,int l1,int r1,int y,int l2,int r2){
        int equal = 1;
        for(int i=0;i<hashCount;++i)
            equal &= (ph[i][x][r1+1] - ph[i][x][l1] + M[i])%M[i]*1ll*coef[i][nax-1-l1]%M[i] == (ph[i][y][r2+1] - ph[i][y][l2] + M[i])%M[i]*1ll*coef[i][nax-1-l2]%M[i];
        return equal;
    }
    // s[x][l1..r1] == s[y][reverse(l2..r2)]
    int equal2(int x,int l1,int r1,int y,int l2,int r2){
        int equal = 1, m = s[y].length();
        for(int i=0;i<hashCount;++i) // tle
            equal &= (ph[i][x][r1+1] - ph[i][x][l1] + M[i])%M[i]*1ll*coef[i][nax-1-l1]%M[i] == (sh[i][y][l2+1] - sh[i][y][r2+2] + M[i])%M[i]*1ll*coef[i][nax-1-(m-r2-1)]%M[i];
        return equal;
    }


    vector<int>L,R;
    void longestPalindromeicSubstring(int k=0){ // k : index of string
        int n = s[k].length();
        int maxl = 0, idx = 0;
        // odd length
        for(int i=0;i<n;++i){
            int l=0,r=min(i,n-i-1)+1; // how much can you expand
            while( l + 1 < r ){
                int m = (l+r)>>1;
                ( equal2(k,i-m,i+m,k,i-m,i+m) ? l : r ) = m;
            }
            if( maxl < 1+2*l )
                maxl = 1+2*l, idx = i-l;
            L[i-l] =max(L[i-l], 1 + 2 *l );
            R[i+l] =max(R[i+l], 1 + 2 *l );
        }
        return;
    }

    long long maxProduct(string str) {
        n = 1, nax = str.length() + 10;
        L = R = vector<int>(str.length());

        s[0] = str;

        compute();

        longestPalindromeicSubstring();

        int N = str.length();
        for(int i=1;i<N;++i){
            L[i] = max(L[i], L[i-1] -2 );
        }
        for(int i=N-2;i>=0;--i){
            R[i] = max(R[i], R[i+1] -2 );
        }

        for(int i=N-2;i>=0;--i){
            L[i] = max(L[i],L[i+1]);
        }

        for(int i=1;i<N;++i){
            R[i] = max(R[i],R[i-1]);
        }
        long long ans = 0;
        for(int i=0;i+1<N;++i){
            ans = max(ans, 1ll * R[i] * L[i+1]);
        }

        return ans;


    }
};
int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
}

