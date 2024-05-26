#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define int long long
using namespace std;	

vector<vector<int>>g;
vector<int>A;
vector<int>B;
vector<int>a;

vector<int> bfs(int u,int n){
	vector<int>vis(n+1);
	vector<int>dis(n+1);
	queue<int>q;
	q.push(u);
	vis[u]=1;
	while( q.size() ){
		int u = q.front(); q.pop();
		for(auto v:g[u]){
			if( !vis[v] ){
				vis[v]=1;
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
	}
	return dis;
}

struct box{
	int a,b,i,bmax;
	bool operator <(const box other){
		return a < other.a;
	}
};

int32_t main(){   
	int n,m,k;cin>>n>>m>>k;
	a=vector<int>(k);
	for(int i=0;i<k;i++){
		cin>>a[i];
	}
	g=vector<vector<int>>(n+1);
	for(int i=1;i<=m;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	vector<int>A=bfs(1,n);
	vector<int>B=bfs(n,n);


	vector<box>arr(k);
	for(int i=0;i<k;i++){
		arr[i].a = A[a[i]];
		arr[i].b = B[a[i]];
		arr[i].i = i;
		arr[i].bmax = 0;
	}

	sort(arr.begin(),arr.end());
	int mx = 0;
	for(int i=k-1;i>=0;i--){
		arr[i].bmax = mx;
		mx=max(mx,arr[i].b);
	}

	mx = 0;
	for(int i=0;i+1<k;i++){
		mx = max( mx , arr[i].a + arr[i].bmax + 1);
	}
	cout << min(mx,A[n]) << endl;




}



