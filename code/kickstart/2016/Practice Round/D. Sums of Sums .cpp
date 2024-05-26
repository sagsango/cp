#include<bits/stdc++.h>
#define int long long 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

pair<int,int> fun(int x,int n,vector<int>&v,vector<int>&dp){
	int cnt=0;
	int sum=0;
	for(int i=0;i<=n;i++){
		int I=upper_bound(v.begin(),v.end(),v[i]+x)-v.begin()-1;
		cnt+=I-i;
		sum+=dp[I]-dp[i]-(I-i)*v[i];
	}
	return {cnt,sum};
}

int solve(int k,int n,vector<int>&v,vector<int>&dp){
	int l=1,r=n*100;
	pair<int,int>s,b;
	while( l<=r ){
		int m=(l+r)/2;
		pair<int,int> x = fun(m,n,v,dp);
		if( x.first <= k ){
			s=x;
			l=m+1;
		}
		else{
			 r = m-1;
			 b=x;
		}
	}
	if( s.first == k )return s.second;
	// let's after sorting : 1 2 3 3 4 5 6 7 : duplicate handling k=3
	int dx = b.first - s.first ;
	int ds = (b.second - s.second )/dx;
	return s.second + max((k-s.first) * ds,0LL);
}
int32_t main()
{
	IOS
	int T;cin>>T;
	for(int t=1;t<=T;t++){
		int n,q;cin>>n>>q;
		vector<int>v(n+1);
		vector<int>dp(n+1);
		for(int i=1;i<=n;i++){
			cin>>v[i];
			v[i]+=v[i-1];
			dp[i]=dp[i-1]+v[i];
		}
		cout<<"Case #"<<t<<":"<<endl;
		while( q-- ){
			int l,r;cin>>l>>r;
			cout<< solve(r,n,v,dp)- solve(l-1,n,v,dp) <<endl;
		}
	}
		
}

	
