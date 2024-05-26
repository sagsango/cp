#include <iostream>
#include <cstring>
#include <string>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;	
	
struct box{
	int token , id , day;
	bool operator <(const box other)const{
		return token > other.token;
	}
};
const int maxn = 5000+5;
priority_queue<box>Q[maxn];
vector<int>Hlist[maxn];
vector<int>capacity(maxn);
vector<pair<int,int>>g[maxn];
vector<int>h(maxn);
vector<int>par(maxn);
int n,maxh=0;

void dfs1(int u=1,int p=0,int w=0){
	par[u]=p;
	h[u]=h[p]+1;
	Hlist[h[u]].push_back(u);
	capacity[u]=w;
	maxh=max(maxh,h[u]);
	for(auto it:g[u]){
		int v = it.first;
		int w2 = it.second;
		if(v!=p){
			dfs1(v,u,w2);
		}
	}
}
			
int32_t main(){   
	cin >> n;
	for(int i=1;i<=n;i++){
		box b;cin>>b.token;
		b.id = i;
		b.day= 0;
		Q[i].push(b);
	}
	for(int i=1;i<n;i++){
		int u,v,w;cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	dfs1();
	
	for(int day=1;day<=n;day++){
		for(int i=2;i<=n-day+1;i++){
			for(int j=0;j<Hlist[i].size();j++){
				int u = Hlist[i][j];
				int processed = 0;
				list<box>B;
				while( Q[u].size() ){
					box b = Q[u].top();Q[u].pop();
					b.day++;
					if( processed < capacity[u] ){
						processed++;
						Q[par[u]].push(b);
					}
					else {
						B.push_back(b);
					}
				}
				while( B.size() ){
					box b = B.front() ; B.pop_front();
					Q[u].push(b);
				}
					
			}
		}
	}
	vector<int>day(maxn);
	while( Q[1].size() ){
		box b = Q[1].top() ; Q[1].pop();
		day[b.id]=b.day;
	}
	
	for(int i=1;i<=n;i++){
		cout<<day[i]<<" ";
	}
	cout<<endl;
			
		
	
	
	
}




