class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        map<int,int>mp[2];
        for(int i=0;i<nums.size();++i){
            ++mp[i&1][nums[i]];
        }
        int sum[2] = {0,0}, cnt[2][2] { {0,0},{0,0} }, key[2][2] = { {0,0}, {0,0} };
        for(int i=0;i<2;++i){
            vector<pair<int,int>>f = {{0,0},{0,0}};
            for(auto [x,y]:mp[i]){
                f.push_back({y,x});
                sum[i] += y;
            }
            sort(f.rbegin(),f.rend());
            cnt[i][0] = f[0].first;
            cnt[i][1] = f[1].first;
            
            key[i][0] = f[0].second;
            key[i][1] = f[1].second;
        }
        if( key[0][0] != key[1][0] ){
            return sum[0] - cnt[0][0] + sum[1] - cnt[1][0];
        }
        int ans = INT_MAX;
        ans = min(ans, sum[0] - cnt[0][0] + sum[1] - cnt[1][1]);
        ans = min(ans, sum[0] - cnt[0][1] + sum[1] - cnt[1][0]);
        
        return ans;
        
        
        
        
        
    }
};
