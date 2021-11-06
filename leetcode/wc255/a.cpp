class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mx = -1e9, mn = +1e9;
        for(auto x:nums){
            if( x > mx ){
                mx = x;
            }
            if( x < mn ){
                mn = x;
            }
        }
        return __gcd(mn,mx);
        
    }
};
