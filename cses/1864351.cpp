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
 
#define int long long 
struct box{
    int i, type, k, a, b;
};
 
const int nax = 2e5+10;
int arr[nax], bit[nax], ans[nax], n, m, sz, qz;
vector< vector<box> >g(nax);
 
void update(int i,int val){
    while( i < nax ){
        bit[i] += val;
        i += i & -i;
    }
}
 
int query(int i,int val=0){
    while( i > 0 ){
        val += bit[i];
        i -= i & -i;
    }
    return val;
}
 
void dfs(int u,int idx){
    //bug4(g.size(),u,g[u].size(),idx);
    if( idx >= g[u].size() ) return;
    int i = g[u][idx].i;
    int type = g[u][idx].type;
    int k = g[u][idx].k;
    int a = g[u][idx].a;
    int b = g[u][idx].b;
    /*
    switch( type ){
        case 1:
            int old = arr[a];
            update(a,b-old);
            arr[a] = b;
            dfs(u,idx+1);
            update(a,old-arr[a]);
            arr[a] = old;
            break;
        case 2:
            ans[i] = query(b) - query(a-1);
            dfs(u,idx+1);
            break;
        case 3:
            dfs(k,0);
            dfs(u,idx+1);
            break;
    }*/
    if( type == 1 ){
        int old = arr[a];
        update(a,b-old);
        arr[a] = b;
        dfs(u,idx+1);
        update(a,old-arr[a]);
        arr[a] = old;
    }else if(type == 2){
        ans[i] = query(b) - query(a-1);
        dfs(u,idx+1);
    }else{
        dfs(k,0);
        dfs(u,idx+1);
    }
}
int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;++i){
        cin >> arr[i], update(i,arr[i]);
    }
    for(int i=0;i<m;++i){
        int type; cin >> type;
        if( type == 1 ){
            int k, a, x; cin >> k >> a >> x;
            g[k-1].push_back({-1,type,k-1,a,x});
        }else if( type == 2 ){
            int k, a, b; cin >> k >> a >> b;
            g[k-1].push_back({qz++,type,k-1,a,b});
        }else{
            int k; cin >> k;
            g[k-1].push_back({i,type,++sz,-1,-1});
        }
    }
    dfs(0,0);
    for(int i=0;i<qz;++i){
        cout << ans[i] <<" ";
    }
    cout << endl;
    
}
