
vector<vector<int>>dp(12+2,vector<int>(12+2));
class Solution {
public:
    int lcs(string a){
        int n = a.length();
        string b = a;
        reverse(b.begin(),b.end());
        for(int i=0;i<=n;++i){
            for(int j=0;j<=n;++j){
                dp[i][j] = 0;
            }
        }
        for(int i=0;i<=n;++i){
            for(int j=0;j<=n;++j){
                if( a[i] == b[j] ){
                    dp[i+1][j+1] = max( dp[i+1][j+1], dp[i][j] + 1);
                }
                dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
                dp[i][j+1] = max(dp[i][j+1],dp[i][j]);
            }
        }
        return dp[n][n];
    }
    int maxProduct(string s){
        int n = s.length();
        int ans = 0;
        for(int i=0;i<1<<n;++i){
            string tmp[2];
            for(int j=0;j<n;++j){
                tmp[i>>j&1] += s[j];
            }
            ans = max(ans, lcs(tmp[0]) * lcs(tmp[1]));
        }
        return ans;
    }
};
