#include<bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
 
const int N = 500 , M = 100'000;
vector<int>U(M+1),V(M+1),W(M+1);
vector<int>used(M+1);
int n,m;


////////////////////  Kruskal's MST  ////////////////////////////
vector<int>par(N+1);
int root(int u){return par[u]<0?u:par[u]=root(par[u]);}
void merge(int u,int v)
{
	if( (u=root(u)) == (v=root(v)) )return ;
	if( par[u] > par[v] )swap(u,v);
	par[u]+=par[v];
	par[v]=u;
}
 
bool edgescmp(const int a , const int b)
{
	return W[a] < W[b];
}
int kruskal(int s=1 )
{
	/////////// Multiple test ///////////
	fill(used.begin(),used.begin()+m+1,0);
	fill(par.begin(),par.begin()+n+1,-1);
	/////////////////////////////////////
	
	vector<int>edges(m+1);
	for(int i=1;i<=m;i++)
	edges[i]=i;
	
	sort(edges.begin()+1,edges.end(),edgescmp);
	
	int cost=0;
	for(int i=1;i<=m;i++)
	{
		int id = edges[i];
		if( root(U[id]) != root(V[id]) )
		{
			merge(U[id],V[id]);
			used[id]=1;
			cost+=W[id];
		}
	}
	return ( -par[root(1)]== n ? cost : 1e15 );
}
////////////////////////////////////////////////////////////
int32_t main()
{
	IOS
	while( cin >> n >> m && ( n || m ) )
	{
		map<string,int>NameId;
		for(int i=1;i<=n;i++)
		{
			string s;cin>>s;
			NameId[s]=i;
		}
		for(int i=1;i<=m;i++)
		{
			string x , y ; cin >> x >> y;
			int u = NameId[x] , v = NameId[y] , w ; cin >> w;
			U[i]=u;
			V[i]=v;
			W[i]=w;
		}
		string s;cin >> s;
		int x = kruskal();
		if( x < 1e15 )  cout << x << endl;
		else cout << "Impossible" << endl;
	}
}
