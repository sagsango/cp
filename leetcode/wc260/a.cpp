class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int mxDiff = 0, mnVal = +1e9;
        for(auto x:nums){
            mxDiff = max(mxDiff, x-mnVal);
            mnVal = min(mnVal,x);
        }
        return mxDiff ? mxDiff : -1;
        
    }
};
