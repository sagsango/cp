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
int dp[1001][101], tmp[101][26], pi[101], n, m;
/*
 TODO: Please see this problem - https://leetcode.com/problems/find-all-good-strings/submissions/ 

 pi[ idx ] = prefix len matched
 tmp[ len_matched ][ cur_char ] = new_len_matched
 dp[ len made ][ len_matched ] = ways
 */
string s;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> s, m = s.length();
    for(int i=1;i<m;++i){
        int j = pi[i-1];
        while( j && s[i] != s[j] ){
            j = pi[j-1];
        }
        if( s[i] == s[j] ){
            ++j;
        }
        pi[i] = j;
    }
    for(int i=0;i<m;++i){
        for(int j=0;j<26;++j){
            int k = i;
            while( k && s[k] - 'A' != j ){
                k = pi[k-1];
            }
            if( s[k] - 'A' == j ){
                ++k;
            }
            tmp[i][j] = k;
        }
    }
    for(int i=0;i<26;++i){
        tmp[m][i] = m;
    }
    dp[0][0] = 1;
    for(int i=0;i<n;++i){
        for(int j=0;j<=m;++j){
            for(int k=0;k<26;++k){
                dp[i+1][tmp[j][k]] = add( dp[i+1][tmp[j][k]], dp[i][j] );
            }
        }
    }
    //bugnm(dp,n+1,m+1);
    cout << dp[n][m] << endl;
}
