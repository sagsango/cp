//small test
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int solve(int d,int mn , int mx , int N , unordered_map<string,int>&dp)
{
	if( mx - mn > 2 || N < 0 || mn <= 0 || mx <= 0)return 0;
	if( N == 0 )return 1;
	string key = to_string(d) + "|" + to_string(mn) + "|" + to_string(mx) + "|" + to_string(N);
	if( dp.find(key)!=dp.end() )return dp[key];
	for(int dx = 0 ; dx <= 2 ; dx++ )
	{
		if( d+dx >= 1)dp[key]+=solve( d+dx , min(mn,d+dx) , max(mx,d+dx) , N - (d+dx) , dp);
	}
	return dp[key];
}
	
	
int32_t main()
{
	IOS
	int T ; cin >> T;
	unordered_map<string,int>dp;
	for(int t=1;t<=T;t++)
	{
		int N , D ;cin>>N>>D;
		int ans=0;
		for(int d = D ; d <= N ; d+=D)
		{
			ans+=solve(d,d,d,N-d,dp);
		}
	    cout <<"Case #"<< t<<": "<< ans <<endl;
   }
}

