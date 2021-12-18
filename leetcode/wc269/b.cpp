class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        long long sum = 0, w = 2*k+1, n = nums.size();
        for(int i=0;i+1<w && i < n;++i){
            sum += nums[i];
        }
        vector<int>ans(n,-1);
        for(int i=w-1;i<n;++i){
            sum += nums[i];
            ans[i-k] = sum / w;
            sum -= nums[i-w+1];
        }
        return ans;
        
    }
};
