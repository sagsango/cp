class Solution {
    #define SPACE ' '
public:
    int mostWordsFound(vector<string>& sentences) {
        int max_words = 0;
        for(auto &s:sentences){
            int space_count = 0;
            for(auto &c:s){
                if( c == SPACE ){
                    space_count += 1;
                }
            }
            max_words = max( max_words, space_count + 1 );
        }
        return max_words;
        
    }
};
