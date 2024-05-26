class Solution {
public:
    
    
    int rev(int n){
        int rn = 0;
        while( n ){
            int d = n % 10;
            
            rn = rn * 10 + d;
            
            n /= 10;
        }
        return rn;
        
    }
    int countNicePairs(vector<int>& nums) {
        
        // nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
        
        
        // nums[i] - rev(nums[i]) == nums[j] - rev(nums[j])
        
        unordered_map<int,int>mp;
        long long ans = 0;
        const int mod = 1e9+7;
        for(auto x:nums){
            int curr = x - rev(x);
            ans += mp[curr];
            mp[curr] += 1;
        }
        return ans % mod;
        
        
        
    }
};
