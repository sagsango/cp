class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size(), pi = 0, ni = 0;
        vector<int>ans;
        while( ans.size() < n ){
            if( ans.size() & 1 ){
                while( ni < n && nums[ni] > 0 )
                    ++ni;
                if( ni < n ){
                    ans.push_back(nums[ni]);
                    ++ni;
                }
            }else{
                while( pi < n && nums[pi] < 0 )
                    ++pi;
                if( pi < n ){
                    ans.push_back(nums[pi]);
                    ++pi;
                }
            }
        }
        return ans;
    }
};
