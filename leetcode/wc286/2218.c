class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<int>dp(k+1);
        for(auto &pile:piles){
            int n = pile.size();
            for(int i=1;i<n;++i){
                pile[i] += pile[i-1];
            }
            for(int j=k;j>=0;--j){
                for(int x=0;x<pile.size() && j-x-1>=0;++x){
                    dp[j] = max(dp[j], dp[j-x-1] + pile[x]);
                }
            }
        }
        return dp[k];
        
    }
};
