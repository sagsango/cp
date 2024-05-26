class Solution {
public:
    int minimumWhiteTiles(string strfloor, int numCarpets, int carpetLen) {
        /*
        dp[len][num_carpet_used] = min_visible_white
        */
        int floor = strfloor.length();
        int dp[floor+1][numCarpets+1];
        for(int i=0; i<=floor; ++i){
            for(int j=0; j<=numCarpets; ++j){
                dp[i][j] = 1e9;
                if(i == 0){
                    dp[i][j] = 0;
                }
            }
        }
        for(int i=0; i<floor; ++i){
            for(int j=0; j<=numCarpets; ++j){
                dp[i+1][j] = min(dp[i+1][j], dp[i][j] + (strfloor[i] != '0'));
                if (j<numCarpets){
                    dp[min(floor,i+carpetLen)][j+1] = min(dp[min(floor,i+carpetLen)][j+1], dp[i][j]);
                }
            }
        }
        int ans = 1e9;
        
        for (int i=0;i<=numCarpets; ++i){
            ans = min(ans, dp[floor][numCarpets]);
        }
        
        return ans;
    }
};
