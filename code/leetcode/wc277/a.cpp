class Solution {
public:
    int countElements(vector<int>& nums) {
        int mx = INT_MIN, mn = INT_MAX;
        for(auto x:nums){
            if( x > mx ){
                mx = x;
            }
            if( x < mn ){
                mn = x;
            }
        }
        int cnt = 0;
        for(auto x:nums){
            if( mn < x && x < mx ){
                ++cnt;
            }
        }
        return cnt;
    }
};
