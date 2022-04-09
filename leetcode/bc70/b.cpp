class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long mx_num = LONG_MIN, mn_num = LONG_MAX, cur_num = 0, count = 0;
        for(auto x:differences){
            cur_num += x;
            if( mx_num < cur_num ){
                mx_num = cur_num;
            }
            if( mn_num > cur_num ){
                mn_num = cur_num;
            }
        }
        for(int first_num = lower; first_num <= upper; ++first_num){
            if( first_num + mx_num <= upper && first_num + mn_num >= lower){
                ++count;
            }
        }
        return count;
        
        
    }
};
