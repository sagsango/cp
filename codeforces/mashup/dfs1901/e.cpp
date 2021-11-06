#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;	
/*
	 while leaf count >= 2 :
	 l = lca(leaf[0],leaf[1])
	 make all the node bad in the subtree if it contais (leaf[0] | leaf[1])
 */

const int maxn = 1005;
vector<vector<int>>g;
vector<int>U(maxn),V(maxn);
vector<int>bad(maxn);
int n , nodes;

void make_graph(){
	g = vector<vector<int>>(n+1);
	for(int i=1;i<n;i++){
		if( !bad[U[i]] && !bad[V[i]] ){
			g[U[i]].push_back(V[i]);
			g[V[i]].push_back(U[i]);
		}
	}
}

pair<int,int> find_leaf(){
	int a=-1,b=-1;
	for(int i=1;i<=n;i++){
		if( g[i].size() == 1 ){
			if( a==-1 )a = i;
			else b = i;
		}
	}
	return {a,b};
}
		
int32_t main(){   
	cin >> n;
	nodes = n;
	for(int i=1;i<n;i++){
		cin>>U[i]>>V[i];
	}
	while( nodes > 1 ){
		make_graph();
		pair<int,int> leaf = find_leaf();
		cout <<"? "<< leaf.first <<" "<< leaf.second << endl , fflush(stdout);
		int l;cin>>l;
		for(auto v:g[l]){
			int ok = 0;
			vector<int>par(n+1);
			queue<int>q;
			q.push(v);
			par[v]=l;
			while( q.size() ){
				int u = q.front(); q.pop();
				if( u == leaf.first || u == leaf.second )ok=1;
				for(auto v:g[u]){
					if( v != par[u] ){
						par[v]=u;
						q.push(v);
					}
				}
			}
			if(ok){
				fill(par.begin(),par.end(),0);
				par[v]=l;
				q.push(v);
				while( q.size() ){
					int u = q.front();q.pop();
					bad[u]=1;
					nodes--;
					for(auto v:g[u]){
						if( v != par[u] ){
							par[v]=u;
							q.push(v);
						}
					}
				}
			}	
		}
	}
	for(int i=1;i<=n;i++){
		if(!bad[i]){
			cout<<"! "<<i<<endl,fflush(stdout);
		}
	}
}



