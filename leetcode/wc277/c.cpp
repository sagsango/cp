class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int,int>mp;
        vector<int>lonely;
        for(auto &x:nums){
            mp[x] += 1;
        }
        for(auto &x:nums){
            if( mp.find(x-1) == mp.end() &&
              mp.find(x+1) == mp.end() &&
              mp[x] == 1 ){
                lonely.push_back(x);
            }
        }
        return lonely;
        
    }
};
