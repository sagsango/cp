#include<bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int M=250,lgN=20,N=4.5e5;
vector<vector<int>>g;
vector<int> tin;
vector<int> tout;
vector<int> clr;
vector<vector<int>>up;
vector<bitset<M>>dp;
int t,n,q,r;

void dfs(int u=1,int p=0)
{
	tin[u]=++t;
	up[u][0]=p;
	dp[u][clr[u]]=1;
	for(int i=1;i<=lgN;i++)
	{
		up[u][i]=up[ up[u][i-1] ][i-1];
	}
	for(auto v:g[u])
	{
		if( v!= p)
		{
			dfs(v,u);
			dp[u]|=dp[v];
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



int32_t main()
{
	int T;cin>>T;
	for(int tc=1;tc<=T;tc++)
	{
		cin>>n>>q>>r;
		t=0;
		g=vector<vector<int>>(n+1);
		up=vector<vector<int>>(n+1,vector<int>(lgN+1));
		tin=vector<int>(n+1);
		tout=vector<int>(n+1);
		clr=vector<int>(n+1);
		dp=vector<bitset<M>>(n+1);
		
		for(int i=1;i<=n;i++)
		cin>>clr[i],clr[i]-=1;
		
		for(int i=1;i<n;i++)
		{
			int u,v;cin>>u>>v;
			u+=1;
			v+=1;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		
		dfs(r+1,0);
		while(q--)
		{
			int u,v;cin>>u>>v;
			cout<<dp[LCA(u+1,v+1)].count()<<endl;
		}
	}
}
