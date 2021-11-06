class Solution {
public:
    int countQuadruplets(vector<int>& arr) {
        int n = arr.size(), cnt = 0;
        int dp[n+2][6][405]; // dp[ till i len ][ taken num ][ sum ] = ways
        memset(dp,0,sizeof(dp));
        dp[0][0][0] = 1;
        for(int i=0;i<n;++i){
            cnt += dp[i][3][arr[i]];
            for(int j=0;j<=3;++j){
                for(int k=0;k<=400;++k){
                    dp[i+1][j][k] += dp[i][j][k];
                }
            }
            for(int j=0;j<3;++j){
                for(int k=0;k+arr[i]<=400;k++){
                    dp[i+1][j+1][k+arr[i]] += dp[i][j][k];
                }
            }
        }
        return cnt;
        
    }
};
