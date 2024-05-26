//https://www.spoj.com/problems/NTICKETS/

// copy paseted the solution of -   https://www.spoj.com/problems/DISQUERY/

#include<bits/stdc++.h>
//#define int long long
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int inf = 1e8 ,lgN=17;
vector<vector<pair<int,int>>>g;
vector<int> tin;
vector<int> tout;
vector<vector<int>>up;
vector<vector<int>>mxw; // Initialise with -inf.
//vector<vector<int>>mnw; // Initialise with +inf.
int t,n;

////////////////////// Binary Lifting ////////////////////////////////////////////////////
void dfs(int u=1,int p=0,int w=0)
{
	tin[u]=++t;
	up[u][0]=p;
	mxw[u][0]=( p ? w : -inf);
	//mnw[u][0]=( p ? w : +inf);
	for(int i=1;i<=lgN;i++)
	{
		up[u][i]=up[ up[u][i-1] ][i-1];
		mxw[u][i]=max(mxw[ up[u][i-1] ][i-1],mxw[u][i-1]);
		//mnw[u][i]=min(mnw[ up[u][i-1] ][i-1],mnw[u][i-1]);
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

int MaxWeightQuery(int u,int v)
{
	
	int l = LCA(u,v);
	int mx = -inf;
	//int mn = +inf;
	if( u!=l )
	{
		for(int i=lgN;i>=0;i--)
	    if( up[u][i] && !isAncestor(up[u][i],l))
	    {
			mx=max(mx,mxw[u][i]);
			//mn=min(mn,mnw[u][i]);
			u=up[u][i];
		}
		mx=max(mx,mxw[u][0]);
		//mn=min(mn,mnw[u][0]);
	}
	if( v!=l )
	{
		for(int i=lgN;i>=0;i--)
	    if( up[v][i] && !isAncestor(up[v][i],l))
	    {
			mx=max(mx,mxw[v][i]);
			//mn=min(mn,mnw[v][i]);
			v=up[v][i];
		}
		mx=max(mx,mxw[v][0]);
		//mn=min(mn,mnw[v][0]);
	}
	return mx;
}

void init()
{
	t=0;
	//lgN=17;
	g=vector<vector<pair<int,int>>>(n+1);
    tin=vector<int>(n+1);
    tout=vector<int>(n+1);
    up=vector<vector<int>>(n+1,vector<int>(lgN+1));
    mxw=vector<vector<int>>(n+1,vector<int>(lgN+1,-inf)); // Initialise with -inf.
    //mnw=vector<vector<int>>(n+1,vector<int>(lgN+1,+inf)); // Initialise with +inf.
}
	
////////////////////////////////////////////////////////////////////////////////////////


int32_t main()
{
	IOS
	while( cin>>n && n)
	{
		init();
		for(int i=1;i<n;i++)
		{
			int u,v,w;cin>>u>>v>>w;
			g[u].push_back({v,w});
			g[v].push_back({u,w});
		}
		dfs();
		int q;cin>>q;
		while( q-- )
		{
			int u,v;cin>>u>>v;
			cout << MaxWeightQuery(u,v) << endl;
		}
		cout<<endl;
	}
	
}
