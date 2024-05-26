class Solution {
public:
    int countEven(int num) {
        int cnt = 0;
        for (int i = 1; i <= num; ++i){
            int dsum = 0;
            int num = i;
            while (num) 
            {
                dsum += num % 10;
                num /= 10;
            }
            if (dsum & 1)
                continue;
            cnt += 1;
        }
        return cnt;
        
    }
};
