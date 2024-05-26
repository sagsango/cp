const int nax = 1e5+10;
#define FREE '.'
int dp[nax][2];
//dp[index][bucket before that index or not] = min count of buckets
class Solution {
public:
    int minimumBuckets(string s){
        int n = s.length();
        for(int i=0;i<=n;++i){
            for(int j=0;j<2;++j){
                dp[i][j] = 1e9;
            }
        }
        dp[0][0] = 0;
        for(int i=0;i<n;++i){
            for(int j=0;j<2;++j){
                if( s[i] == FREE ){
                    dp[i+1][1] = min(dp[i+1][1],dp[i][j]+1);
                    dp[i+1][0] = min(dp[i+1][0],dp[i][j]);
                }else{
                    if( j == 0 && s[i+1] != FREE )
                        continue;
                    if( s[i+1] == FREE )
                        dp[i+2][1] = min(dp[i+2][1],dp[i][j]+1);
                    if( j ){
                        dp[i+1][0] = min(dp[i+1][0],dp[i][j]);
                    }
                }
                
            }
        }
        int ans = min(dp[n][0],dp[n][1]);
        return ans < 1e9 ? ans : -1;
    }
};
