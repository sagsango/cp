/*Kruskal's*/
#include<bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int MOD = 1e9;
const int N = 100'000 , M = 1000'000;
vector<int>U(M+1),V(M+1),W(M+1);
vector<int>used(M+1);
int n,m;

////////////////////  Kruskal's MST  ////////////////////////////
vector<int>par(N+1,-1);
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
	return W[a] > W[b];
}
int kruskal(int s=1 )
{
	vector<int>edges(m+1);
	for(int i=1;i<=m;i++)
	edges[i]=i;
	
	sort(edges.begin()+1,edges.end(),edgescmp);
	
	vector<int>dp(100'000+2);

	int cost=0;
	for(int i=1;i<=m;i++)
	{
		int id = edges[i];
		if( root(U[id]) != root(V[id]) )
		{
			int cnt = ( par[root(U[id])] * par[ root(V[id]) ]);
			dp[0]+=cnt;
			dp[0]%=MOD;
			dp[W[id]+1]-=cnt;
			dp[W[id]+1]+=MOD;
			dp[W[id]+1]%=MOD;
			
			
			merge(U[id],V[id]);
			used[id]=1;
		}
	}
	vector<int>present(100'000+2);
	for(int i=1;i<=m;i++)
	present[ W[i] ]++;
	
	for(int i=1;i<=100'000;i++)
	{
		dp[i]+=dp[i-1];
		dp[i]%=MOD;
		cost+=dp[i]*present[i]*i;
		cost%=MOD;
	}
	
	return cost;
}
////////////////////////////////////////////////////////////
	
int32_t main()
{
	IOS	
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	cin>>U[i]>>V[i]>>W[i];
	cout << kruskal() << endl;
}
	

