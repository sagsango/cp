class Solution {
public:
    bool winnerOfGame(string colors) {
        int a = 0, b = 0, i = 0, n = colors.size();
        while( i < n ){
            int j = i;
            while( j < n && colors[i] == colors[j] )
                ++j;
            ( colors[i] == 'A' ? a : b ) += max(0,j-i-2);
            i = j;
        }
        if( b >= a )
            return false;
        return true;
        
    }
};
