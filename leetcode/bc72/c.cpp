class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if( finalSum & 1 ){
            return {};
        }
        set<int>taken;
        int n = 2;
        vector<long long>ans;
        while( n <= finalSum ){
            if( !taken.count(n) ){
                ans.push_back(n);
                finalSum -= n;
            }
            n += 2;
        }
        n = finalSum;
        if( n && !taken.count(n) ){
                n += ans.back();
                ans.pop_back();
                ans.push_back(n);
        }
       
        return ans;
        
    }
};
