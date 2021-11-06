#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <list>
#define int long long
using namespace std;	
	
const int maxn = 305;
vector<pair<int,int>>g[maxn];
vector<int>h(maxn);
vector<int>par(maxn);
vector<int>edg(maxn);
vector<int>used(maxn);
int n=0,leaf=0,l;

void dfs(int u=1,int p=0,int I=0){
	h[u]=h[p]+1;
	par[u]=p;
	edg[u]=I;
	for(auto it:g[u]){
		int v = it.first;
		int i = it.second;
		if(v!=p){
			dfs(v,u,i);
		}
	}
}

int lca(int u,int v){
	while( u!=v){
		if( h[u] > h[v] )u=par[u];
		else v= par[v];
	}
	return u;
}

int32_t main(){   
	cin>>n;
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		g[u].push_back({v,i});
		g[v].push_back({u,i});
	}
	for(int i=2;i<=n;i++){
		if(g[i].size()==1)leaf++;
	}
	dfs();
	vector<int>ans;
	int prev = 0;
	for(int i=1;i<=leaf;i++){
		int curr;cin>>curr;
		if( !prev ){
			prev = curr;
			list<int>v;
			while( curr!=1 ){
				v.push_back(curr);
				used[ edg[curr] ]++;
				curr = par[curr];
			}
			v.push_back(curr);
			while( v.size() ){
				ans.push_back( v.back() );
				v.pop_back();
			}
		}
		else {
			int tempprev = curr;
			l = lca(prev,curr);
			list<int>v;
			while( prev !=l ){
				used[ edg[prev] ]++;
				prev = par[prev];
				v.push_back(prev);
			}
			while( v.size() ){
				ans.push_back( v.front() );
				v.pop_front();
			}
			while( curr !=l ){
				v.push_back(curr);
				used[ edg[curr] ]++;
				curr=par[curr];
			}
			while( v.size() ){
				ans.push_back( v.back() );
				v.pop_back();
			}
			prev = tempprev;
		}		
	}
	while( prev != 1 ){
		used[ edg[prev] ]++;
		prev = par[prev];
		ans.push_back(prev);
	}
	for(int i=1;i<n;i++){
	   if(used[i]!=2 ){
		   cout<<-1<<endl;
		   return 0;
	   }
	}
	cout<<endl;
	for(auto v:ans){
		cout<<v<<" ";
	}
	cout<<endl;
			
			
			
	
}




