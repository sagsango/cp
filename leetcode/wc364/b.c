class Solution {
public:
    long long maximumSumOfHeights(vector<int>& arr) {
        long long ans = 0;
        int n = arr.size();
        for(int i=0;i<n;++i){
            long long l = arr[i], r = arr[i], sum = arr[i];
            for(int j=i+1;j<n;++j){
                r = min(1ll*arr[j], r);
                sum += r;
            }
            for(int j=i-1;j>=0;--j){
                l = min(1ll*arr[j], l);
                sum += l;
            }
            ans = max(ans, sum);
        }
        return ans;
       
    }
};
