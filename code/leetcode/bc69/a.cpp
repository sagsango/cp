class Solution {
    char toLower(char c){
        if(  'A' <= c && c <= 'Z' ){
            return c -'A' + 'a';
        }
        return c;
    }
    char toUpper(char c){
        if( 'a' <= c && c <= 'z' ){
            return c - 'a' + 'A';
        }
        return c;
    }
public:
    string capitalizeTitle(string title) {
        int i = 0, n = title.length();
        while( i < n ){
            int j = i;
            while( j < n && title[j] != ' ')
                ++j;
            int length = j - i;
            for(int k=i;k<j;++k){
                title[k] = toLower(title[k]);
            }
            if( length > 2 ){
              title[i] = toUpper(title[i]);
            }
            i = j + 1;
        }
        return title;
    }
};
