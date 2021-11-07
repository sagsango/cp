class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides){
        vector<vector<pair<int,int>>>avialbeRidesFrom(n+1);
        for(auto v:rides){
            int start = v[0];
            int end = v[1];
            int tip = v[2];
            avialbeRidesFrom[ start ].push_back({end,tip});
        }
        vector<long long>dp(n+1,0);
        for(int i=1;i<=n;++i){
            dp[i] = max(dp[i],dp[i-1]);
            for(auto [end,tip]:avialbeRidesFrom[i]){
                dp[end] = max( dp[end], dp[i] + tip + end - i);
            }
        }
        return dp[n];
        
        
    }
};
