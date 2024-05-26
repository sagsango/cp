class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        int n = arr.size();
        vector<long long> dis(n);
        unordered_map<int,long long>idxCount;
        unordered_map<int,long long>idxSum;
        for(int i=0;i<n;++i){
            dis[i] += idxCount[arr[i]] * i - idxSum[arr[i]];
            idxSum[arr[i]] += i;
            idxCount[arr[i]] += 1;
        }
        idxCount.clear();
        idxSum.clear();
        for(int i=n-1;i>=0;--i){
            dis[i] += idxSum[arr[i]] - idxCount[arr[i]] * i;
            idxSum[arr[i]] += i;
            idxCount[arr[i]] += 1;
        }
        return dis;
        
    }
};
