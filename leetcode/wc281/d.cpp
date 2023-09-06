class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        
        int bit = 0;
        map<int,int> given;
        for (int i=2; i<=k; ++i){
            while( k % i == 0){
                given[i] += 1;
                k /= i;
                bit += 1;
            }
        }
        
        int nax = 1<<bit;
        vector<int>dp(nax), have_mask(nums.size()), need_mask(nums.size());
        
        for(int i = 0; i<nums.size(); ++i){
            int all = 0, n = nums[i];
            for(auto [f,s]:given){
               int cur = 0;
               for(int i=0;i<s;++i){
                   if(n % f == 0){
                       cur += 1;
                       n /= f;
                   }
               }
               for (int j=0; j<cur; ++j){
                   have_mask[i] |= 1 << (all+j);
               }
                for(int j=0; j<given[f]-cur;++j){
                   need_mask[i] |= 1<<(all+j);
                }
                
                all += s;
            }
        }
        
        //return 0;
      
        
        for(int i=0; i<nums.size();++i){
            dp[have_mask[i]] += 1;
        }
        
        
        for (int i = 0; i < bit; i++){
            
           
            for(int j=nax - 1; j>=0; --j){
                if( j >> i & 1){
                    continue;
                }
                dp[j] += dp[j^(1<<i)];
            }
         
        }
        
        
        
       
        long long ans = 0;
        for(int i=0; i<nums.size();++i){
            ans += dp[need_mask[i]];
            if( (need_mask[i]|have_mask[i]) == have_mask[i]){
                ans -= 1; // remove myself;
            }
           
        }
        
        
        
        assert( ans % 2 == 0);
       
        return ans >> 1;
        
    }
};
