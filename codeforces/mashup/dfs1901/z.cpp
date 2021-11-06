#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>

#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define bug1( x ) cerr << (#x) <<"="<< x << endl;
#define bug2( x , y ) cerr << (#x) <<"="<< (x) << "    " << (#y) << "="<< (y) << endl;
#define bug3( x , y , z ) cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << endl;
#define bug4( x , y , z , w) cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << endl;
#define bug5( x , y , z , w ,p) cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << "    " << (#p) <<"="<< p << endl;
#define bug6( x , y , z , w ,p , q) cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << "    " << (#p) <<"="<< p << "    " << (#q) <<"="<< q << endl;
#define bugn( x , n ){ cerr<<(#x)<<":";for(int i=0;i<n;i++)cout<<(#x)<<"["<<i<<"]:"<< x[i] << "    "; cout<<endl;}
#define bugnm( x , n , m ){ cerr<<(#x)<<endl;for(int i=0;i<n;i++){ cout<<"Row #"<<i<<":"; for(int j=0;j<m;j++) cout<<x[i][j]<<"     "; cout << endl;}}

#define __builtin_popcount __builtin_popcountll
#define sqrt sqrtl
#define cbrt cbrtl

using namespace std;

typedef unsigned long long ul;
typedef long double ld;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector <vi> vvi;
typedef vector<vvi> vvvi;
 

vector<pair<int,int>>g[7],tpl;
vector<int>vis(100),U(100),V(100),top(7);
int m,c,s;
void dfs(int u){
	while( top[u] < g[u].size() ){
		int v = g[u][top[u]].first, i = g[u][top[u]].second;
		++top[u];
		if( !vis[i] ){
			vis[i] = 1;
			dfs(v);
			tpl.push_back({i,U[i]!=u});
		}
	}
}
int32_t main(){
	cin >> m;
	for(int i=0,u,v;i<m;++i)
		cin >> U[i] >> V[i], g[U[i]].push_back({V[i],i}), g[V[i]].push_back({U[i],i}), s = U[i];
	for(int i=0;i<7;++i){
		if(  g[i].size() & 1 )
			++c, s = i;
	}
	dfs(s);
	int ok = ( c == 0 || c == 2 );
	for(int i=0;i<m;++i)
		if(!vis[i])
			ok = 0;
	if( !ok )
		return cout << "No solution" << endl,0;
	reverse(tpl.begin(),tpl.end());
	//bug2(U[4],V[4]);
	for(auto [i,x]:tpl){
		if( x )
			swap(U[i],V[i]);
		cout << i+1 <<" "<<( x ? '-' : '+' )<<endl; //":" << U[i] <<" "<<V[i] << endl;
	}
	

}

/*
 * long long or int?
 * index out of bound? 
 * Tested on own test case?corner?
 * Make more general solution.
 * Read Read Read Read ....
 */

