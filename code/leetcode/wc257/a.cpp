class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        // nums[a] + nums[b] + nums[c] == nums[d], and
        // a < b < c < d
        
        // nums[a] + nums[b]  == nums[d] - nums[c]
        // a < b < c < d
        
        unordered_map<int,int>hashMap;
        int cnt = 0, n = nums.size();
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                int key = nums[j] - nums[i];
                cnt += hashMap[key];
            }
            for(int j=0;j<i;++j){
                int key = nums[i] + nums[j];
                hashMap[key] += 1;
            }
        }
        return cnt;
        
    }
};
