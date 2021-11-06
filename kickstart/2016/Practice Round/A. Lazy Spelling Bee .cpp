
#include<bits/stdc++.h>
#define int long long 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int MOD =1e9+7;
int solve(int i,int n,string &s,vector<map<char,int>>&dp)
{
	if( i==n )return 1LL;
	if( i-1 >= 0 ){
		if( dp[i].find(s[i-1]) == dp[i].end() ){
			dp[i][s[i-1]]=solve(i+1,n,s,dp);
		}
	}
	if( i+1 < n ){
		if( dp[i].find(s[i+1]) == dp[i].end() ){
			dp[i][s[i+1]]=solve(i+1,n,s,dp);
		}
	}
	if( dp[i].find(s[i]) == dp[i].end() ){
			dp[i][s[i]]=solve(i+1,n,s,dp);
	}
	int ans=0;
	for(auto [f,x]:dp[i]){
		ans+=x;
		ans%=MOD;
	}
	return ans;
}
int32_t main()
{
	IOS
	int T;cin>>T;
	for(int t=1;t<=T;t++)
	{
		string s;cin>>s;
		int n=s.length();
		vector<map<char,int>>dp(n);
		cout<<"Case #"<<t<<":"<<" "<< solve(0,n,s,dp) <<endl;
	}
		
}

	
