#include <iostream>
#include <queue>
#include <vector>
#define int long long
using namespace std;	


int32_t main()
{   
	int n,m,s,l;cin>>n>>m>>s;
	vector<vector<pair<int,int>>>g(n+1);
	vector<int>U(m+1),V(m+1),W(m+1);
	for(int i=1;i<=m;i++){
		cin>>U[i]>>V[i]>>W[i];
		g[U[i]].push_back({V[i],i});
		g[V[i]].push_back({U[i],i});
	}
	cin>>l;
	
	queue<int>q;
	vector<int>d(n+1,1e17);
	vector<int>inq(n+1);
	d[s]=0;
	inq[s]=1;
	q.push(s);
	while( q.size() ){
		int u = q.front(); q.pop();
		inq[u]=0;
		for(auto it:g[u]){
			int v = it.first;
			int w = W[it.second];
			if( d[v] > d[u] + w ){
				d[v]=d[u]+w;
				if(!inq[v]){
					inq[v]=1;
					q.push(v);
				}
			}
		}
	}
	int cnt = 0;
	for(int i=1;i<=n;i++){
		if( d[i] == l ){
			cnt++;
		}
	}
	for(int i=1;i<=m;i++){
		int dux = l - d[U[i]];
		int dvx = l - d[V[i]];
		if(  (dux > 0 && dux < W[i] && d[V[i]] + W[i] - dux >= dux + d[U[i]] ) && 
			 (dvx > 0 && dvx < W[i] && d[U[i]] + W[i] - dvx >= dvx + d[V[i]] ) && 
			 dux + dvx == W[i] )cnt+=1;

        else if(  (dux > 0 && dux < W[i] &&   d[V[i]] + W[i] - dux >= dux + d[U[i]] ) && 
			 (dvx > 0 && dvx < W[i] && d[U[i]] + W[i] - dvx >= dvx + d[V[i]] ) )cnt+=2;
			 
	    else if(  (dux > 0 && dux < W[i] && d[V[i]] + W[i] - dux >= dux + d[U[i]] ) ||
				  (dvx > 0 && dvx < W[i]&& d[U[i]] + W[i] - dvx >= dvx + d[V[i]] )  )
				cnt+=1;
			 
	}
	cout << cnt << endl;
}



