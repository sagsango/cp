class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        // | x - y | = k
        // x - y = +k or x - y = -k
        // x = +k + y.or x = -k + y
        
        unordered_map<int,int>hashMap;
        int cnt = 0;
        for(auto y:nums){
            int x;
            x = +k + y;
            cnt += hashMap[x];
            x = -k + y;
            cnt += hashMap[x];
            
            hashMap[y] += 1;
        
        }
        return cnt;

        
    }
};
