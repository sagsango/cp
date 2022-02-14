class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int ones = 0, zeros = 0, n = nums.size(), mxsum = 0;
        for(auto &x: nums){
            ones += x == 1;
        }
        for(int i=0;i<n;++i){
            if( ones + zeros > mxsum ){
                mxsum = ones + zeros;
            }
            zeros += nums[i] == 0;
            ones -= nums[i] == 1;
        }
        if( ones + zeros > mxsum ){
            mxsum = ones + zeros;
        }
        ones = zeros = 0;
        for(auto &x: nums){
            ones += x == 1;
        }
        vector<int>ans;
        for(int i=0;i<n;++i){
            if( ones + zeros == mxsum){
                ans.push_back(i);
            }
            zeros += nums[i] == 0;
            ones -= nums[i] == 1;
        }
        if( ones + zeros == mxsum){
                ans.push_back(n);
        }
        return ans;
        
    }
};
