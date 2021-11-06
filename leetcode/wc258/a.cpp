class Solution {
public:
    string reversePrefix(string word, char ch) {
        int i = 0, n = word.length();
        while( i < n && word[i] != ch )
            ++i;
        if( i != n ){
            int j = 0;
            while(  j  < i ){
                swap(word[i],word[j]);
                --i;
                ++j;
            }
        }
        return word;
        
    }
};
