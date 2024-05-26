class Solution {
public:
    long long getDescentPeriods(vector<int>& prices){
        long long sum = 0, prv = 1e9, cnt = 1;
        for(auto &p:prices){
            if( prv - 1 == p ){
                cnt += 1;
            }else{
                cnt = 1;
            }
            sum += cnt;
            prv = p;
        }
        return sum;
        
    }
};
