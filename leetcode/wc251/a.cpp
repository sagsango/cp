class Solution {
    int dsum(char c){
        int sum = 0;
        int num = c - 'a' + 1;
        while( num ){
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
public:
    int getLucky(string s, int k) {
        int sum = 0;
        for(auto c:s){
            sum += dsum(c);
        }
        for(int i=0;i<k-1;++i){
            int num = sum;
            int tsum = 0;
            while( num ){
                tsum += num % 10;
                num /= 10;
            }
            sum = tsum;
        }
        return sum;
    }
};
