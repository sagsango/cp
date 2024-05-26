#include<bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

vector<vector<pair<int,int>>>g;
vector<int> tin;
vector<int> tout;
vector<vector<int>>up;
vector<vector<int>>d;
int t,n,lgN;

//////////////////////////// Binary Lifting   ///////////////////////////////////
void dfs(int u=1,int p=0,int w=0)
{
	tin[u]=++t;
	up[u][0]=p;
	d[u][0]=w;
	for(int i=1;i<=lgN;i++)
	{
		up[u][i]=up[ up[u][i-1] ][i-1];
		d[u][i]=d[ up[u][i-1] ][i-1]+d[u][i-1];
	}
	for(auto it:g[u])
	{
		int v=it.first;
		int w=it.second;
		if( v!= p)
		{
			dfs(v,u,w);
		}
	}
	tout[u]=++t;
}

int isAncestor(int u,int v)
{
	return tin[u]<=tin[v] && tout[v]<=tout[u];
}

int LCA(int u,int v)
{
	if( isAncestor(u,v) )return u;
	if( isAncestor(v,u) )return v;
	
	for(int i=lgN;i>=0;i--)
	if( up[u][i] && !isAncestor(up[u][i],v))
	u=up[u][i];
	
	return up[u][0];
}

int DisQuery(int u,int v)
{
	
	int l = LCA(u,v);
	int dis = 0;
	if( u!=l )
	{
		for(int i=lgN;i>=0;i--)
	    if( up[u][i] && !isAncestor(up[u][i],l))
	    {
			dis+=d[u][i];
			u=up[u][i];
		}
		dis+=d[u][0];
		u=up[u][0];
	}
	if( v!=l )
	{
		for(int i=lgN;i>=0;i--)
	    if( up[v][i] && !isAncestor(up[v][i],l))
	    {
			dis+=d[v][i];
			v=up[v][i];
		}
	   dis+=d[v][0];
	   v=up[v][0];
	}
	return dis;
}
void init()
{
	t=0;
	lgN=20;
	g=vector<vector<pair<int,int>>>(n+1);
	tin=vector<int>(n+1);
	tout=vector<int>(n+1);
	up=vector<vector<int>>(n+1,vector<int>(lgN+1));
	d=vector<vector<int>>(n+1,vector<int>(lgN+1));
}
	
/////////////////////////////////////////////////////////////////////////////////////////////


int32_t main()
{
	IOS
	cin >> n ;
	init();
	for(int i=1;i<n;i++)
	{
		int u,v,w;cin>>u>>v>>w;
		u++;
		v++;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	dfs();
	int q;cin>>q;
	while( q-- )
	{
		int u,v;cin>>u>>v;
		u++;
		v++;
		cout<< DisQuery(u,v) << endl;
	}
		
	
	
	
}
