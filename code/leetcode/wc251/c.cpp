class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& stu, vector<vector<int>>& men) {
        int n = stu.size(), m = stu[0].size();
        // dp[no of stu tken ][mask of taken men ] = max_sum
        int dp[n+1][1<<n], cmp[n][n];
        for(int i=0;i<n+1;++i){
            for(int j=0;j<1<<n;++j){
                dp[i][j] = -1e9;
            }
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                cmp[i][j] = 0;
                for(int k=0;k<m;++k){
                    cmp[i][j] += stu[i][k] == men[j][k];
                }
            }
        }
        dp[0][0] = 0;
        for(int i=0;i<n;++i){
            for(int j=0;j<1<<n;++j){
                for(int k=0;k<n;++k){
                    if( j >> k & 1 )
                        continue;
                    dp[i+1][j|1<<k] = max( dp[i+1][j|1<<k], dp[i][j] + cmp[i][k]);
                }
            }
        }
        return dp[n][(1<<n)-1];
        
    }
};
