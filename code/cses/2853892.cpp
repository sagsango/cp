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
 
/*
TODO: Edge weight = 1, so do bfs, how to keep track of vis node, use bitmasking
*/
 
const int nax = 3*3, Block = 4, Mask = 0b1111;
vector<int>g[nax];
const int dx[4] = {+1,-1,+0,-0};
const int dy[4] = {+0,-0,+1,-1};
int n = 3;
 
inline bool valid(int x,int y){
	return x >= 0 && x < n && y >= 0 && y < n;
}
 
unordered_set < long long > vis;;
 
inline int getMask(long long &msk, int idx){
	return (  ( msk >> ( idx * Block ) ) & Mask );
}
 
inline void setMask(long long &msk, int idx, long long new_val){
	long long org_val = getMask(msk,idx);
	msk ^= org_val << ( idx * Block );
	msk ^= new_val << ( idx * Block );
}
 
int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			for(int k=0;k<4;++k){
				int x = i + dx[k], y = j + dy[k];
				if( valid(x,y) ){
					g[i*n+j].push_back(x*n+y);
				}
			}
		}
	}
	long long  msk = 0, good_msk = 0;
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			long long val; cin >> val, --val;
			int idx = i * n + j;
			setMask(msk,idx,val);
			setMask(good_msk,idx,idx);
		}
	}
	queue<pair<long long,int>>q;
	vis.insert(msk);
	q.push({msk,0});
	while( q.size() ){
		long long msk = q.front().first, cst = q.front().second;
		q.pop();
		if( msk == good_msk ){
			cout << cst << endl;
			return 0;
		}
		//cout << msk <<" "<< cst << endl;
		for(int u=0;u<nax;++u){
			for(auto v:g[u]){
				int u_val = getMask(msk,u);
				int v_val = getMask(msk,v);
				swap(u_val,v_val);
				long long new_msk = msk;
				setMask(new_msk,u,u_val);
				setMask(new_msk,v,v_val);
				if( !vis.count(new_msk) ){
					vis.insert(new_msk);
					q.push({new_msk,cst+1});
				}
			}
		}
	}
	return -1;
}
 
