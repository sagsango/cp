class Solution {
public:
    int numOfPairs(vector<string>& nums, string target){
        unordered_map<string,int>hashMap;
        for(auto s:nums){
            hashMap[s]+=1;
        }
        int ans = 0;
        for(auto s:nums){
            hashMap[s] -= 1;
            if( s.length() < target.length() ){
                int i = 0;
                while( i < s.length() && s[i] == target[i] )
                    ++i;
                if( i == s.length() ){
                    ans += hashMap[target.substr(i)];
                }
            }
            hashMap[s] += 1;
        }
        return ans;
    }
};
