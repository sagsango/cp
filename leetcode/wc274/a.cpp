class Solution {
public:
    bool checkString(string s) {
        int n = s.length(), indx_before_a_appear = 0, index_after_b_appear = n - 1;
        
        while( indx_before_a_appear  < n && s[indx_before_a_appear] == 'a' )
            ++indx_before_a_appear;
        
        while( index_after_b_appear >= 0 && s[index_after_b_appear] == 'b' )
            --index_after_b_appear;
        
        if( index_after_b_appear + 1 == indx_before_a_appear)
            return true;
        return false;
        
    }
};
