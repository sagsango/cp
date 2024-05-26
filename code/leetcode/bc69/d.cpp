class Solution {
public:
    bool possibleToStamp(vector<vector<int>>& g, int h, int w) {
        int n = g.size(), m = g[0].size();
        vector<vector<int>>dp, sum;
        dp = sum = vector<vector<int>>(n+5,vector<int>(m+5));
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                sum[i][j] = g[i][j] + (i?sum[i-1][j]:0) + (j?sum[i][j-1]:0) - (i&&j ?sum[i-1][j-1]: 0);
            }
        }
        auto check = [&](int x,int y){
            int x1 = x, y1 = y, x2 = x + h - 1, y2 = y + w - 1;
            if( x2 >= n || y2 >= m ){
                return false;
            }
            return (sum[x2][y2] - (x1?sum[x1-1][y2]:0) - (y1?sum[x2][y1-1]:0) + (x1&&y1?sum[x1-1][y1-1]:0)) == 0 ;
        };
        
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if( check(i,j) ){
                    dp[i][j] += 1;
                    dp[i+h][j] -= 1;
                    dp[i][j+w] -= 1;
                    dp[i+h][j+w] += 1;
                }
            }
        }
        
        for(int i=1;i<n;++i){
            for(int j=0;j<m;++j){
                dp[i][j] += dp[i-1][j];
            }
        }
        for(int i=0;i<n;++i){
            for(int j=1;j<m;++j){
                dp[i][j] += dp[i][j-1];
            }
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if( g[i][j] == 0 && dp[i][j] == 0 )
                    return false;;
            }
        }
        return true;
        
    }
};
