#pragma GCC target("popcnt")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")


 int i, j, msk;
class Solution {
    
   #define smax(a,b) {a =  a < b ? b : a; }
    
public:
    int maximumANDSum(vector<int>& arr, int m) {
        ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int n = arr.size();
        vector<int>dp(1<<(m<<1),0), dp2;
        for(i=0;i<n;++i){
            dp2 = dp;
            for(msk=0;msk<1<<(m<<1);++msk){
                for(j=0;j<m;++j){
                    if( !( (msk >> ((j<<1)|0)) & 1)  ){
                        smax(dp2[msk | (1<<((j<<1)|0)) ], dp[msk] + ((j+1)&arr[i]));
                    }
                    if( !( (msk >> ((j<<1)|1)) & 1)  ){
                        smax(dp2[msk | (1<<((j<<1)|1)) ], dp[msk] + ((j+1)&arr[i]));
                    }
                    
                }
            }
            dp = dp2;
        }
        int mx = 0;
        for(int i=0;i<1<<(m<<1);++i){
            mx = max(mx, dp[i]);
        }
        return mx;
        
        
    }
};
