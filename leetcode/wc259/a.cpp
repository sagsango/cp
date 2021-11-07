class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        unordered_map<string,int>mp;
        mp["X++"] = +1;
        mp["++X"] = +1;
        mp["--X"] = -1;
        mp["X--"] = -1;
        int val = 0;
        for(auto x:operations){
            val += mp[x];
        }
        return val;
        
    }
};
