class Solution {
public:
    int minimumMoves(string s) {
        int n = s.length(), i = 0, cnt = 0;
        while( i < n ){
            if( s[i] == 'X' ){
                ++cnt;
                i += 3;
            }else{
                ++i;
            }
        }
        return cnt;
        
    }
};
