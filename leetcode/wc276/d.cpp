class Solution {
    typedef long long ll;
public:
    long long maxRunTime(int n, vector<int>& arr){
        
        long long sum = 0;
        for(auto &x:arr){
            sum += x;
        }
        sort(arr.rbegin(),arr.rend());
        for(auto &x:arr){
            if( x > sum / n ){
                n -= 1;
                sum -= x;
            }else{
                return sum /n;
            }
        }
        return 0;
        
        
    }
};
