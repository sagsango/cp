#include<bits/stdc++.h>
#define int long long 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;


int32_t main()
{
	IOS
	int T;cin>>T;
	for(int t=1;t<=T;t++){
		int n,X,K,A,B,C;
		cin>>n>>X>>K>>A>>B>>C;
		long double a = (long double)A/100.00;
		long double b = (long double)B/100.00;
		long double c = (long double)C/100.00;
		
		long double ans=0;
		for(int i=0;i<=30;i++){
			int x=(X>>i)&1;
			int k=(K>>i)&1;
			long double dp[n+1][2];
			memset(dp,0,sizeof(dp));
			dp[0][x]=1;
			for(int j=0;j<n;j++){
				dp[j+1][0&k]+=dp[j][0]*a;
				dp[j+1][0|k]+=dp[j][0]*b;
				dp[j+1][0^k]+=dp[j][0]*c;
				
				dp[j+1][1&k]+=dp[j][1]*a;
				dp[j+1][1|k]+=dp[j][1]*b;
				dp[j+1][1^k]+=dp[j][1]*c;
			}
			ans+=(1LL<<i)*(dp[n][1]);
		}
		cout<<"Case #"<<t<<":"<<" "<< fixed << setprecision(10) << ans <<endl;
	}
		
}

	
