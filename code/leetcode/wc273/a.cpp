class Solution {
public:
    bool isSameAfterReversals(int num) {
        if( num && num % 10 == 0 ){
            return false;
        }
        return true;
        
    }
};
