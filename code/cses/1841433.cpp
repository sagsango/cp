//
//  blank.cpp
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
 
// dp[len][last digit][non zero: 0 = zero , 1 = non zero ][flag : 0 = smaller, 1 = equal ]
 
 
vector<int> number(ll n){
    vector<int>num;
    while( n ){
        num.push_back(n%10);
        n /= 10;
    }
    while( num.size() < 20u ){
        num.push_back(0);
    }
    reverse(num.begin(),num.end());
    return num;
}
ll dp[21][10][2][2];
ll solve(vector<int>num){
    for(int i=0;i<21;++i){
        for(int j=0;j<10;++j){
            for(int k=0;k<2;++k){
                for(int l=0;l<2;++l){
                    dp[i][j][k][l] = 0;
                }
            }
        }
    }
    dp[0][0][0][1] = 1;
    for(int i=0;i<20;++i){
        for(int j=0;j<10;++j){
            for(int k=0;k<2;++k){
                int d = 0;
                for(d=0;d<num[i];++d){
                    if( !k || j != d )
                        dp[i+1][d][k|(d>0)][0] += dp[i][j][k][1];
                }
                if( !k || j != d )
                    dp[i+1][d][k|(d>0)][1] += dp[i][j][k][1];
                for(d=0;d<10;++d){
                    if( !k || j != d )
                        dp[i+1][d][k|(d>0)][0] += dp[i][j][k][0];
                }
            }
        }
    }
    ll ans = 0;
    for(int j=0;j<10;++j){
        for(int k=0;k<2;++k){
            for(int l=0;l<2;++l){
                ans += dp[20][j][k][l];
            }
        }
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll l, r; cin >> l >> r;
    
    cout << solve(number(r)) - ( l ? solve(number(l-1)) : 0 ) << endl;
    
    
    
    
}


