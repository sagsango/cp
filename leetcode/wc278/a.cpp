class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int>st;
        for(auto &x:nums){
           st.insert(x);
        }
        while( st.find(original) != st.end() ){
            original <<= 1;
        }
        return original;
        
    }
};
