#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#define int long long
using namespace std;	
	
const int maxn = 1e5 + 10;
vector<vector<int>>g(maxn);
vector<int>dp(maxn);
vector<int>u(maxn),v(maxn),w(maxn),h(maxn);
int n;
void dfs(int u=1,int p=0){
	h[u]=h[p]+1;
	dp[u]+=1;
	for(auto v:g[u]){
		if(v!=p){
			dfs(v,u);
			dp[u]+=dp[v];
		}
	}
}
long double nc3(int n){
	if( n < 3 ) return 0;
	return   1.00 * n * ( n-1 ) * ( n-2 ) / 6.00;
}
long double nc2(int n){
	if( n < 2 ) return 0;
	return   1.00 * n * ( n-1 ) / 2.00;
}
int32_t main()
{   
	IOS
	cin >> n;
	for(int i=1;i<n;i++){
		cin>>u[i]>>v[i]>>w[i];
		g[u[i]].push_back(v[i]);
		g[v[i]].push_back(u[i]);
	}
	dfs();
	long double curr = 0;
	for(int i=1;i<n;i++){
		int a =  ( h[u[i]] < h[v[i]] ? dp[v[i]] : dp[u[i]] );
		int b =  n - a;
		long double c =  2.00 * w[i] * ( nc2(a)* b + nc2(b ) * a )/ nc3(n);
		curr+=c;
	}
	int q;cin>>q;
	while( q-- ){
		int i,new_w ; cin >> i >> new_w ;
	    int a =  ( h[u[i]] < h[v[i]] ? dp[v[i]] : dp[u[i]] );
		int b =  n - a;
		curr -=   2.00 * w[i] * ( nc2(a)* b + nc2(b ) * a )/ nc3(n);
		w[i]  = new_w;
		curr +=   2.00 * w[i] * ( nc2(a)* b + nc2(b ) * a )/ nc3(n);
		cout << fixed << setprecision(10) << curr <<endl;
	}
	
}




