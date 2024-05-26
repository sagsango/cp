

class Solution {
public:
    int numberOfUniqueGoodSubsequences(string s) {
        int n = s.length(), mod = 1e9+7;
        /*int dp[n+1][2], prv[2] = {0,0};
        memset(dp,0,sizeof(dp));
        s = '$' + s;
        dp[0][0] = 1;
        for(int i=1;i<=n;++i){
           for(int j=0;j<2;++j){
               dp[i][j] = 2 * dp[i-1][j] % mod;
               int k = prv[s[i] - '0'];
               dp[i][j] = ( dp[i][j] - dp[k][j] + mod ) % mod;
           }
           (dp[i][s[i]-'0'] += 1) %= mod;
            prv[s[i]-'0'] = i;
        }
        return dp[n][1] + (bool)(dp[n][0] > 1 );*/
        
        vector<int>dp(n+1);
        int prv[2] = {-1,-1}, zero = 0;
        for(auto x:s){
            zero |= x == '0';
        }
        s = '$' + s;
        int i = 1;
        while( i <= n && s[i] == '0' )
            ++i;
        if( i > n )
            return zero;
        dp[i] = 1;
        for(++i;i<=n;++i){
            (dp[i] = 2*dp[i-1])%=mod;
            int k = s[i] - '0';
            if( prv[k] != -1 ){
                dp[i] -= dp[prv[k]-1];
                (dp[i] += mod )%=mod;
            }
            prv[k] = i;
        }
        return dp[n] + zero;
        
    }
};
    
