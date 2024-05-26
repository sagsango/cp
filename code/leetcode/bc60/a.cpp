class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int left = 0, right = 0, n = nums.size();
        for(int i=0;i<n;++i){
            right += nums[i];
        }
        for(int i=0;i<n;++i){
            right -= nums[i];
            if( left == right ){
                return i;
            }
            left += nums[i];
        }
        return -1;
        
    }
};
