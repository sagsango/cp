#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#define int long long
using namespace std;	
	

int32_t main(){   
	int n,m;cin>>n>>m;
	set<int> bad[n+1];
	for(int i=1;i<=m;i++){
		int u,v;cin>>u>>v;
		bad[u].insert(v);
		bad[v].insert(u);
	}
	set<int>lef;
	for(int i=1;i<=n;i++){
		lef.insert(i);
	}

	int cmp=0;
	for(int i=1;i<=n;i++){
		if(lef.count(i)){
			cmp++;
			queue<int>q;
			q.push(i);
			lef.erase(i);
			while(q.size()){
				int u=q.front();
				q.pop();
				vector<int>cool;
				for(auto v:lef){
					if(!bad[u].count(v)){
						cool.push_back(v);
					}
				}
				for(auto v:cool){
					q.push(v);
					lef.erase(v);
				}
			}
		}
	}
	cout<<cmp-1<<endl;
}




