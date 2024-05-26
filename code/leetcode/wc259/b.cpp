class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size(), tmp;
        vector<int>mx(n),mn(n);
        
        tmp = INT_MIN;
        for(int i=0;i<n;++i){
            tmp = max(tmp,nums[i]);
            mx[i] = tmp;
        }
        
        
        tmp = INT_MAX;
        for(int i=n-1;i>=0;--i){
            tmp = min(tmp,nums[i]);
            mn[i] = tmp;
        }
        
        int cnt = 0;
        for(int i=1;i<=n-2;++i){
            if( mx[i-1] < nums[i] && nums[i] < mn[i+1] ){
                cnt += 2;
            }else if( nums[i-1] < nums[i] && nums[i] < nums[i+1] ){
                cnt += 1;
            }else
                cnt += 0;
        }
        return cnt;
        
        
    }
};
