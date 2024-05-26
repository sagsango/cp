class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int i = 0, n = s.length(), j = 0;
        string ans;
        for(int i=0;i<s.length();++i){
            if( j < spaces.size() && spaces[j] == i ){
                ans.push_back(' ');
                ++j;
            }
            ans.push_back(s[i]);
        }
        return ans;
        
    }
};
