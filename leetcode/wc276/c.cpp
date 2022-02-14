class Solution {
    typedef long long ll;
    void smax(ll &a,ll b){
        if( a < b )
            a = b;
    }
public:
    long long mostPoints(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<ll>dp(n+10,-1e18);
        dp[0] = 0;
        for(int i=0;i<n;++i){
            // solve
                smax(dp[min(i+arr[i][1]+1,n+1)],dp[i] + arr[i][0]);
            // not solve
                smax(dp[i+1], dp[i]);

        }
        return dp[n+1];
        
        
    }
};
