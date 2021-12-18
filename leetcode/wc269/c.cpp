class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mn_i = 0, mx_i = 0, n = nums.size();
        for(int i=0;i<n;++i){
            if( nums[i] > nums[mx_i] ){
                mx_i = i;
            }
            if( nums[i] < nums[mn_i] ){
                mn_i = i;
            }
        }
        if( mx_i == mn_i ){
            return 1;
        }
        if( mn_i > mx_i ){
            swap(mx_i,mn_i);
        }
        int ans = mn_i + 1 +  n - mx_i;
        ans = min(ans, mx_i + 1);
        ans = min(ans, n - mn_i);
        return ans;
        
    }
};
