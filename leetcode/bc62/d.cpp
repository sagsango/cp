class Solution {
public:
    int waysToPartition(vector<int>& nums, int k){
        /*long long rsum = 0, lsum = 0, ans = 0;
        int n = nums.size();
        unordered_map<int,int>Lmp,Rmp;
        for(int i=0;i<n;++i){
            rsum += nums[i];
            Rmp[nums[i]] += 1;
        }
        for(int i=1;i<n;++i){
            lsum += nums[i-1];
            rsum -= nums[i-1];
            Lmp[nums[i-1]] += 1;
            Rmp[nums[i-1]] -= 1;
            
            if( lsum == rsum ){
                ans += 1;
            }
            
            // lsum - x + k = rsum   =>    x = lsum - rsum + k
            // lsum = rsum - y + k   =>.   y = rsum - lsum + k
            
            ans += Lmp[lsum-rsum+k];
            ans += Rmp[rsum-lsum+k];
        }*/
        
        long long rsum = 0, lsum = 0, ans = 0;
        int n = nums.size();
        unordered_map<long long,vector<int>>Lmp,Rmp;
        for(int i=0;i<n;++i){
            rsum += nums[i];
        }
        for(int i=1;i<n;++i){
            lsum += nums[i-1];
            rsum -= nums[i-1];
            
            if( lsum == rsum ){
                ans += 1;
            }
            
            // lsum - x + k = rsum   =>    x = lsum - rsum + k
            // lsum = rsum - y + k   =>.   y = rsum - lsum + k
            
            Lmp[lsum-rsum+k].push_back(i-1);
            Rmp[rsum-lsum+k].push_back(i+0);

        }
       
        for(int i=0;i<n;++i){
            long long key = nums[i], cnt = 0;
            
            if( Lmp.find(key) != Lmp.end() ){ // how many numbers are greater or equal to i.
                
                int x = upper_bound(Lmp[key].begin(),Lmp[key].end(),i-1) - Lmp[key].begin();
                cnt += Lmp[key].size() - x;
                
            }
            if( Rmp.find(key) != Rmp.end() ){ // how many numbers are less or equal to i.
                
                cnt += upper_bound(Rmp[key].begin(),Rmp[key].end(),i) - Rmp[key].begin();
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};
