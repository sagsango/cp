#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;	


class DSU{
	public :
	int n;
	vector<int>par;
	void init(int n){
		this->n=n;
		par=vector<int>(n,-1);
	}
	int root(int u){ return par[u] < 0 ? u : par[u]=root(par[u]);}
	void merge(int u,int v){
		if( (u=root(u)) == (v=root(v)) )return;
		if( par[u] > par[v] )swap(u,v);
		par[u]+=par[v];
		par[v]=u;
	}
};

int32_t main(){   
	int n,m;cin>>n>>m;
	vector<int>a(m),b(m);
	for(int i=0;i<m;i++){
		cin>>a[i]>>b[i];
		a[i]--;
		b[i]--;
	}
	vector<DSU>ldp(m);
	vector<DSU>rdp(m);
	for(int i=0;i<m;i++){
		ldp[i].init(n);
		rdp[i].init(n);
	}
	for(int i=0;i<m;i++){
		ldp[i].merge(a[i],b[i]);
		if( i+1 < m ){
			ldp[i+1].par = ldp[i].par;
		}
	}
	for(int i=m-1;i>=0;i--){
		rdp[i].merge(a[i],b[i]);
		if( i-1 >=0 ){
			rdp[i-1].par=rdp[i].par;
		}
	}
	int q;cin>>q;
	while( q--){
		DSU curr;
		curr.init(n);
		int l,r;cin>>l>>r;
		l--,r--;
		if( l-1 >= 0 ){
			for(int i=0;i<n;i++){
				curr.merge(i,ldp[l-1].root(i));
			}
		}
		if( r+1 < m ){
			for(int i=0;i<n;i++){
				curr.merge(i,rdp[r+1].root(i));
			}
		}
		int cnt = 0;
		for(int i=0;i<n;i++){
			if( curr.par[i] < 0 )cnt++;
		}
		cout<<cnt<<endl;
	}
	
			
}


