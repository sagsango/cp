class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int x){
        int n = mat.size(), m = mat[0].size(), sum = 0;
        for(int i=0;i<n;++i){
            int mn = 1e9;
            for(int j=0;j<m;++j){
                mn = min(mn,mat[i][j]);
            }
            sum += mn;
        }
        if( sum > x ){
            return sum - x;
        }
        int nax = 2 * x;
        vector<int>dp(nax+1);
        dp[0] = 1;
        for(int i=0;i<n;++i){
            vector<int>dp2(nax+1);
            for(int j=0;j<m;++j){
                for(int k=0;k+mat[i][j]<=nax;++k){
                    dp2[k+mat[i][j]] |= dp[k];
                }
            }
            dp = dp2;
        }
        int mn = 1e9;
        for(int i=0;i<=nax;++i){
            if( dp[i] ){
                mn = min(mn, abs(x - i));
            }
        }
        return mn;
        
        
    }
};
