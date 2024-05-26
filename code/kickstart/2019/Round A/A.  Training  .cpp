#include<bits/stdc++.h>
#define int long long
using namespace std;
int32_t main()
{
    int T;cin>>T;
    for(int t=1;t<=T;t++)
    {
        int n,p,ans=1e18;cin>>n>>p;
        vector<int>A(n+1),dp(n+1);
        for(int i=1;i<=n;i++)
        {
            cin>>A[i];
        }
        sort(A.begin(),A.end());
        for(int i=1;i<=n;i++)dp[i]=dp[i-1]+A[i];
        for(int i=0;i<=n-p;i++)
        {
            int sum=dp[i+p]-dp[i];
            int max_sum=A[i+p]*p;
            ans=min(ans,max_sum-sum);
        }
        if(ans<0)ans=0;
        cout<<"Case "<<"#"<<t<<":"<<" "<<ans<<endl;
    }
}
