#include<bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

vector<vector<int>>g;
vector<int>h;
vector<int>par;
int n;

void dfs(int u=1,int p = 0){

	h[u] = h[p] + 1;
	par[u] = p;
	for(auto v : g[u])	
	{
		if(v!=p)
		{
			dfs(v,u);
		}
	}
}

int LCA(int v,int u){
	while( u!=v )
	{
		if( h[v] > h[u] ) v = par[v];
		else u=par[u];
	}
	return u;
}

int32_t main()
{
	int T;cin>>T;
	for(int tc=1;tc<=T;tc++)
	{
		cin>>n;
		g=vector<vector<int>>(n+1);
		h=vector<int>(n+1);
		par=vector<int>(n+1);
		
		for(int i=1;i<=n;i++)
		{
			int m,u=i;cin>>m;
			for(int j=1;j<=m;j++)
			{
				int v;cin>>v;
				g[u].push_back(v);
				g[v].push_back(u);
			}
		}
		
		dfs();
		cout<<"Case "<<tc<<":"<<endl;
		int q;cin>>q;
		while(q--)
		{
			int u,v;cin>>u>>v;
			cout<<LCA(u,v)<<endl;
		}
	}
}
