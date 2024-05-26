#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define int long long
using namespace std;	
		
const int maxn = 2000;
vector<int>par(maxn,-1);
vector<vector<int>>dis(maxn,vector<int>(maxn));
vector<int>d(maxn);
vector<int>p(maxn);
int n;

int root(int u){ return par[u] < 0 ? u : par[u] = root(par[u]);}
void merge(int u,int v){
	if( (u=root(u)) == (v=root(v)) )return;
	if( par[u] > par[v] )swap(u,v);
	par[u]+=par[v];
	par[v]=u;
}

struct box{
	int u,v,w;
	bool operator <(const box other)const{
		return w > other.w;
	}
};

priority_queue< box > pq;
vector<vector<pair<int,int>>>g(maxn);

int32_t main(){   
	cin >> n ;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>dis[i][j];
			pq.push({i,j,dis[i][j]});
		}
	}
	while( par[ root(0) ] != -n  && pq.size() ){
		box b = pq.top(); pq.pop();
		if( root(b.u) == root(b.v) || b.w==0)continue;
		else 
		{
			merge(b.u,b.v);
			g[b.u].push_back({b.v,b.w});
			g[b.v].push_back({b.u,b.w});
		}
	}
	
	
	for(int i=0;i<n;i++){
		fill(p.begin(),p.begin()+n,-1);
		fill(d.begin(),d.begin()+n,0);
		queue<int>q;
		q.push(i);
		d[i]=0;
		while( q.size() ){
			int u = q.front(); q.pop();
			for(auto it:g[u]){
				int v = it.first;
				int w = it.second;
				if( v != p[u] ){
					p[v]=u;
					d[v]=d[u]+w;
					q.push(v);
				}
			}
		}
		for(int j=0;j<n;j++){
			if(dis[i][j]!=d[j] || ( j!=i && p[j]==-1 )){
				cout<<"NO"<<endl;return 0;
			}
		}				
	}
	cout << "YES" << endl;
}



