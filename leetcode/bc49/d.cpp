map<pair<long long,int>,int>dp;
const long long MASK = (31);
int m;

int solve(long long mask,int rem){
    
    if( dp.find({mask,rem}) != dp.end() )
        return dp[{mask,rem}];
    
    
    int ans = 0;
    for(int i=1;i<m;++i){
        long long x = ( mask >> (( i - 1 )*5) ) & MASK;
        if( x ){
            ans = max(ans, (rem == 0 ) + solve( mask ^ ( x << ((i-1)*5) ) ^ ( (x-1) << ((i-1)*5) ),(rem+i)%m) );
        }
    }
    dp[{mask,rem}] = ans;
    
    return ans;
}
class Solution {
    

public:
    int maxHappyGroups(int M, vector<int>& a){
        /*
        // 0,1,2,3,4,5,6,7,8 | 9
    
        count[1,,,,,,,,,8][rem]  = max satisfies

				total states = no of ways x0 + x1 + x2 + ... x8 = 30
										 = ncr(9+30-1,9-1) = ncr(38,8) = 48903492 
				
				states * rem <= 1e8
TODO: calculate compexity always
				
        
        
        
        1,2,3,4,5..8, rem
        
        */
            
        
        dp.clear();
        m = M;
        
        vector<long long>cnt(m);
        for(auto x:a){
            cnt[x % m] += 1;
        }
        
        long long mask = 0;
        for(int i=1;i<m;++i){
            mask |= cnt[i] << ( ( i - 1 ) * 5  );
        }
        
        return solve(mask,0) + cnt[0];
        
        
            
       
        
        
        
        
        
    }
};
