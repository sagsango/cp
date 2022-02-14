#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
typedef long double ld;

// "AND", "OR", "XOR", "NOT" , "IN"
const int maxn = 1e6+10;
vector<string>s(maxn);
vector<int>val(maxn,-1),dp(maxn,-1),g[maxn],ans(maxn);
int n,x,y;

void dfs(int u){
	if( s[u] == "AND" )
		dfs(g[u][0]),dfs(g[u][1]),val[u] = val[g[u][0]] & val[g[u][1]];
	else if( s[u] == "OR" )
		dfs(g[u][0]),dfs(g[u][1]),val[u] = val[g[u][0]] | val[g[u][1]];
	else if( s[u] == "XOR")
		dfs(g[u][0]),dfs(g[u][1]),val[u] = val[g[u][0]] ^ val[g[u][1]];
	else if( s[u] == "NOT")
		dfs(g[u][0]),val[u] = not val[ g[u][0] ];
}

// k: 0 meanse unset, 1 meanse set, 2 meanse set or unset.
void solve(int u,int k){
	if( s[u] == "IN" ){
		dp[u] = (k == 2 ? 1 :( (val[u]^1) == k ));
	}else{
		if( s[u] == "AND" ){
			if( k == 1 ){
				if(val[g[u][0]])
					solve(g[u][1],1);
				if(val[g[u][1]])
					solve(g[u][0],1);
			}
			if( k == 0 ){
				if(val[g[u][0]])
					solve(g[u][1],0);
				else
					solve(g[u][1],2);
				if(val[g[u][1]])
					solve(g[u][0],0);
				else
					solve(g[u][0],2);
			}
			if( k == 2 ){
				solve(g[u][0],2);
				solve(g[u][1],2);
			}
		}else if( s[u] == "OR" ){
			if( k == 1){
				if(val[g[u][0]])
					solve(g[u][1],2);
				else 
					solve(g[u][1],1);
				if(val[g[u][1]])
					solve(g[u][0],2);
				else
					solve(g[u][0],1);
			}
			if( k == 0 ){
				if(val[g[u][1]]==0)
					solve(g[u][0],0);
				if(val[g[u][0]]==0)
					solve(g[u][1],0);
			}
			if( k == 2 ){
				solve(g[u][0],2);
				solve(g[u][1],2);
			}
		}else if( s[u] == "XOR" ){
			if( k == 1){
				if(val[g[u][0]])
					solve(g[u][1],0);
				else 
					solve(g[u][1],1);
				if(val[g[u][1]])
					solve(g[u][0],0);
				else 
					solve(g[u][0],1);
			}
			if( k == 0 ){
				if(val[g[u][0]])
					solve(g[u][1],1);
				else
					solve(g[u][1],0);
				if(val[g[u][1]])
					solve(g[u][0],1);
				else
					solve(g[u][0],0);
			}
			if( k == 2 ){
				solve(g[u][0],2);
				solve(g[u][1],2);
			}
		}else if( s[u] == "NOT" ){
			if( k == 1){
				solve(g[u][0],0);
			}
			if( k == 0 ){
				solve(g[u][0],1);
			}
			if( k == 2 ){
				solve(g[u][0],2);
			}
		}
	}
}

int32_t main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if( s[i] == "IN" )
			cin >> val[i];
		else{
			if( s[i] == "NOT" )
				cin>>x,g[i].push_back(x);
			else
				cin>>x>>y,g[i].push_back(x),g[i].push_back(y);
		}
	}
	dfs(1); // What will be the node value, from the subtree.


	// Now we will find if root value is 1
	// then what can be coresponding input value
	// for ith node, when other input do not change.
	// we will update ans accordigly ( meanse after change the input value ).
	int u = 1;
	if( s[1] == "AND" ){
		if(val[g[u][0]])
			solve(g[u][1],1);
		if(val[g[u][1]])
			solve(g[u][0],1);
	}else if( s[1] == "OR" ){
		if(val[g[u][0]])
			solve(g[u][1],2);
		else 
			solve(g[u][1],1);
		if(val[g[u][1]])
			solve(g[u][0],2);
		else 
			solve(g[u][0],1);
	}else if( s[1] == "XOR" ){
		if(val[g[u][0]])
			solve(g[u][1],0);
		else
			solve(g[u][1],1);
		if(val[g[u][1]])
			solve(g[u][0],0);
		else 
			solve(g[u][0],1);
	}else if( s[1] == "NOT" ){
		solve(g[u][0],0);
	}else if( s[1] == "IN"  ){
		solve(1,1);
	}
	for(int i=1;i<=n;i++)
		if(s[i]=="IN")
			cout<<(dp[i]==1?1:0);
			
}

