class Solution {
    bool isPalindrome(string &s){
        int i = 0, j = s.length() - 1;
        while( i < j ){
            if( s[i] != s[j] ){
                return false;
            }
            i++, --j;
        }
        return true;
    }
public:
    string firstPalindrome(vector<string>& words) {
        for(auto &s:words){
            if( isPalindrome(s) ){
                return s;
            }
        }
        return "";
    }
};
