class Solution {
public:
    bool squareIsWhite(string s) {
        int x = ( s[0] -'a' ) + ( s[1] - '1' );
        return x % 2;
        
    }
};
