#include<bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
 
const int lgN = 20;
vector<vector<pair<int,int>>>G;
vector<int> tin;
vector<int> tout;
vector<int> h;
vector<vector<int>>up;
vector<vector<int>>d;
int t, n ;

void dfs(int u=1,int p=0,int w=0)
{
	tin[u]=++t;
	up[u][0]=p;
	h[u]=h[p]+1;
	d[u][0]=w;
	for(int i=1;i<=lgN;i++)
	{
		up[u][i]=up[ up[u][i-1] ][i-1];
		d[u][i]=d[ up[u][i-1] ][i-1]+d[u][i-1];
	}
	for(auto it:G[u])
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
	}
	return dis;
}
int KthNode(int u,int v,int k)
{
	k--;
	int l = LCA(u,v);
	int d = h[u]-h[l];
	if( k <= d )
	{
		int ans = u;
		for(int i=lgN;i>=0;i--)
		{
			if( (1LL<<i) <= k )
			{
				k-=1LL<<i;
				ans=up[ans][i];
			}
		}
		return ans;
		
	}
	else
	{
		k = h[u]-h[l] + h[v] - h[l] - k;
		int ans = v;
		for(int i=lgN;i>=0;i--)
		{
			if( (1LL<<i) <= k )
			{
				k-=1LL<<i;
				ans=up[ans][i];
			}
		}
		return ans;
	}
	return -1;
	
}
/////////////////////////////////////////////////////////
int32_t main()
{
	int T;cin>>T;
	while( T-- )
	{
		t=0;
		cin >> n ;
		G=vector<vector<pair<int,int>>>(n+1);
		tin=vector<int>(n+1);
		tout=vector<int>(n+1);
		h=vector<int>(n+1);
		up=vector<vector<int>>(n+1,vector<int>(lgN+1));
		d=vector<vector<int>>(n+1,vector<int>(lgN+1));
		
		for(int i=1;i<n;i++)
		{
			int u,v,w;cin>>u>>v>>w;
			G[u].push_back({v,w});
			G[v].push_back({u,w});
		}
		
		dfs();
		
		string s;
		while( cin >> s && s!="DONE" )
		{
			if( s == "DIST" )
			{
				int u,v;cin>>u>>v;
				cout << DisQuery(u,v) << endl;
			}
			else
			{
				int u,v,k;cin>>u>>v>>k;
				cout << KthNode(u,v,k) << endl;
			}
		}
		cout << endl;
	}
}
			
		
