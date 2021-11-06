#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define int long long
using namespace std;	
	
// TODO: Digest it

int32_t main(){   
	int t;cin>>t;
	while( t-- ){
		int n;cin>>n;
		vector<int>g[n+1];
		vector<int>cool(n+1);
		for(int i=1;i<n;i++){
			int u,v;cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		int k1;cin>>k1;
		vector<int>v1(k1);
		for(int i=0;i<k1;i++){
			cin>>v1[i];
			cool[v1[i]]++;
		}
		int k2;cin>>k2;
		vector<int>v2(k2);
		for(int i=0;i<k2;i++){
			cin>>v2[i];
		}
		cout<<"B "<< v2[0] << endl,fflush(stdout);
		int s;cin>>s;
		vector<int>d(n+1,1e15);
		vector<int>vis(n+1);
		queue<int>q;
		vis[s]=1;
		d[s]=0;
		q.push(s);
		while( q.size() ){
			int u = q.front(); q.pop();
			for(auto v:g[u]){
				if( !vis[v] ){
					d[v]=d[u]+1;
					vis[v]=1;
					q.push(v);
				}
			}
		}
		int xnode = -1 , mind = 1e18;
		for(int i=1;i<=n;i++){
			if( cool[i] && d[i] < mind ){
				xnode = i;
				mind  = d[i];
			}
		}
		cout<<"A "<<xnode<<endl,fflush(stdout);
		int y;cin>>y;
		int ok = 0;
		for(int i=0;i<k2;i++){
			if( v2[i]==y){
				ok=1;
			}
		}
		if( ok ){
			cout<< "C " << xnode << endl,fflush(stdout);
		}
		else cout<< "C "<<-1<<endl,fflush(stdout);
	}
			
	
}




