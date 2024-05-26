#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;	

int32_t main(){   
	priority_queue< pair<int,int> > pq;
	map<int,int>mp;
	int n;cin>>n;
	vector<int>a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
		pq.push({a[i],i});
		mp[a[i]]++;
	}
	while( true ){
		int i = pq.top().second; pq.pop();
		int x = a[i];
		while( x && mp.count(x) ){
			x>>=1;
		}
		if( x == 0 )break;
		mp[a[i]]=0;
		a[i]=x;
		mp[a[i]]=1;
		pq.push({a[i],i});

	}
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;

}




