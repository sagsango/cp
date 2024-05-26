class Solution {
public:
    vector<long long> sumOfThree(long long num){
        // x - 1 + x + x + 1 = num 
        // x = num / 3;
        if( num % 3 )
            return {};
        long long x = num/3;
        return {x-1,x,x+1};
    }
};
