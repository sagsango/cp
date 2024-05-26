class Solution {
public:
    int minSessions(vector<int>& a, int m) {
        int n = a.size();
        int dp[1<<n][m+1]; // taken mask , time left in a session
        for(int i=0;i<1<<n;++i){
            for(int j=0;j<=m;++j){
                dp[i][j] = 1e9;
            }
        }
        dp[0][m] = 1;
        for(int i=0;i<1<<n;++i){
            for(int j=0;j<=m;++j){
                for(int k=0;k<n;++k){
                    if( i >> k & 1 )
                        continue;
                    if( a[k] <= j ){
                        dp[i^(1<<k)][j-a[k]] = min(dp[i^(1<<k)][j-a[k]],dp[i][j]);
                    }else{
                        dp[i^(1<<k)][m-a[k]] = min(dp[i^(1<<k)][m-a[k]], dp[i][j] + 1);
                    }
                }
            }
        }
        int ans = 1e9;
        for(int i=0;i<=m;++i){
            ans = min(ans, dp[(1<<n)-1][i]);
        }
        return ans;
    }
};
