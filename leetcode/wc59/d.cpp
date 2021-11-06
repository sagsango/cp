class Solution {
public:
    
    const int mod = 1e9+7;
    void add(int &x,int y){
        x += y;
        if( x >= mod ){
            x -= mod;
        }
    }
    
    int numberOfCombinations(string s){
        if( s.empty() || s[0] == '0' )
            return 0;
        
        int n = s.length();
        int lcp[n+2][n+2],dp[n+2][n+2];
        memset(lcp,0,sizeof(lcp));
        memset(dp,0,sizeof(dp));
        s = '$' + s;
        for(int i=n;i>=1;--i){
            for(int j=n;j>=1;--j){
                if( s[i] == s[j] ){
                    lcp[i][j] = 1 + lcp[i+1][j+1];
                }
            }
        }
        
        dp[0][0] = 1;
        for(int i=1;i<=n;++i){
            
            // prefix sum 
            for(int j=1;j<=n;++j){
                add(dp[i][j],dp[i-1][j-1]);
            }
            
            
            // forword dp 
            if( i + 1 <= n && s[i+1] != '0'){
                for(int j=1; j<=i && i+j <= n;++j){
                    int l = j, k = lcp[i-j+1][i+1];
                    if( k < l && s[i-j+1+k] > s[i+1+k] ){
                        l+=1;
                    }
                    if( i + l <= n){
                        add(dp[i+l][l],dp[i][j]);
                        // and x =1....n all we be => dp[i+l+x][l+x] += dp[i][j]
                       
                    }
                }
            }
        }
        
        int ans = 0;
        for(int i=1;i<=n;++i){
            add(ans, dp[n][i]);
        }
        
        return ans;
        
    }
};
