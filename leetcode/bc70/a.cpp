
class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int n = cost.size(), sum = 0;
        for(int i=n-1;i>=0;){
            for(int j=0;j<2 && i - j >= 0;++j){
                sum += cost[i-j];
            }
            i -= 3;
        }
        return sum;
    }
};
