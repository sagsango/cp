class Solution {
public:
    int minOperations(vector<int>& nums){
        int n = nums.size();
        sort(nums.begin(),nums.end());
        nums.erase(unique(nums.begin(),nums.end()),nums.end());
        int ans = INT_MAX;
        for(auto x:nums){
            int got = upper_bound(nums.begin(),nums.end(),x+n-1) - lower_bound(nums.begin(),nums.end(),x);
            ans = min(ans, n - got);
        }
        return ans;
        
    }
};
