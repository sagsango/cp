class Solution {
public:
    vector<int> recoverArray(vector<int>& nums){
        sort(nums.begin(),nums.end());
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;++i){
            mp[nums[i]] += 1;
        }
        auto tmp = mp;
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                int d = nums[j] - nums[i];
                if( !d ||   d % 2 )
                    continue;
                vector<int>lower;
                for(int k=0;k<n;++k){
                    if( mp[nums[k]] ){
                        if( mp.find(nums[k]+d) == mp.end() || mp[nums[k]+d] == 0  ){
                            break;
                        }
                        mp[nums[k]+d] -= 1;
                        mp[nums[k]+0] -= 1;
                        lower.push_back(nums[k]+d/2);
                    }
                }
                if( 2*lower.size() == n  ){
                    return lower;
                }
                
                for(auto &x:lower){
                    mp[x+d/2] += 1;
                    mp[x-d/2] += 1;
                }
            }
        }
        return {};
        
    }
};
