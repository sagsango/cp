#include<bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
 
const int N = 10000 , M = 100000;
vector<int>U(M+1),V(M+1),W(M+1);
int n,m,A;
 
////////////////////  Kruskal's MST  ////////////////////////////
vector<int>par(N+1);
vector<int>cost(N+1);
int root(int u){return par[u]<0?u:par[u]=root(par[u]);}
void merge(int u,int v,int w)
{
	if( w >= A  )return;
	if( (u=root(u)) == (v=root(v)) )return ;
	if( par[u] > par[v] )swap(u,v);
	par[u]+=par[v];
	par[v]=u;
	cost[u]+=cost[v]-A+w;
}
 
bool edgescmp(const int a , const int b)
{
	return W[a] < W[b];
}
void kruskal(int s=1 )
{
	/////////// Multiple test ///////////
	fill(par.begin(),par.begin()+n+1,-1);
	fill(cost.begin(),cost.begin()+n+1,A);
	/////////////////////////////////////
	
	vector<int>edges(m+1);
	for(int i=1;i<=m;i++)
	edges[i]=i;
	
	sort(edges.begin()+1,edges.end(),edgescmp);
	
	for(int i=1;i<=m;i++)
	{
		int id = edges[i];
		if( root(U[id]) != root(V[id]) )
		{
			merge(U[id],V[id],W[id]);
		}
	}
}
////////////////////////////////////////////////////////////
	
int32_t main()
{
	IOS	
	int T;cin>>T;
	for(int t=1;t<=T;t++)
	{
		cin>>n>>m>>A;
		for(int i=1;i<=m;i++)
		cin>>U[i]>>V[i]>>W[i];
		kruskal();
		
		int airPort = 0;
		int totCost = 0;
		for(int i=1;i<=n;i++)
		{
			if( par[i] < 0 )
			{
				totCost += cost[i];
				airPort += 1;
			}
		}
		cout << "Case #"<<t<<": "<<totCost << " " << airPort << endl;
	}
}
