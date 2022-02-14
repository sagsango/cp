class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int w = 0, n = nums.size();
        auto arr = nums;
        for(int i=0;i<n;++i){
            w += nums[i];
            arr.push_back(nums[i]);
        }
        if( w == 0 || w == n ){
            return 0;
        }
        int cnt = 0, ans = n, N = n << 1;
        for(int i=0;i+1<w;++i){
            cnt += arr[i] == 0;
        }
        for(int i=w-1;i<N;++i){
            cnt += arr[i] == 0;
            ans = min(ans,cnt);
            cnt -= arr[i-w+1] == 0;
        }
        return ans;
        
        
    }
};
