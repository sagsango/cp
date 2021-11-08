class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3){
        unordered_set<int>s[3];
        for(auto x:nums1){
            s[0].insert(x);
        }
        for(auto x:nums2){
            s[1].insert(x);
        }
        for(auto x:nums3){
            s[2].insert(x);
        }
        unordered_map<int,int>mp;
        for(int i=0;i<3;++i){
            for(auto x:s[i]){
                mp[x] += 1;
            }
        }
        vector<int>ans;
        for(auto [x,y]:mp){
            if( y >= 2 ){
                ans.push_back(x);
            }
        }
        return ans;
        
    }
};
