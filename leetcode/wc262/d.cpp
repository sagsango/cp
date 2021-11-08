class Solution {
public:
    int minimumDifference(vector<int>& nums){
        vector<int>a,b;
        long long all = 0;
        for(int x:nums){
            if( a.size() < b.size() ){
                a.push_back(x);
            }else{
                b.push_back(x);
            }
            all += x;
        }
        unordered_map<int,vector<int>>mp;
        int n = a.size();
        for(int i=0;i<1<<n;++i){
            long long sum = 0;
            int cnt = 0;
            for(int j=0;j<n;++j){
                if( i >> j & 1 ){
                    sum += a[j];
                    cnt += 1;
                }
            }
            mp[cnt].push_back(sum);
        }
        for(unordered_map<int,vector<int>>::iterator it = mp.begin();it != mp.end(); ++it){
            sort(it->second.begin(),it->second.end());
            it->second.erase(unique(it->second.begin(),it->second.end()),it->second.end());
        }
        long long ans = 1e18;
        for(int i=0;i<1<<n;++i){
            long long sum = 0;
            int cnt = 0;
            for(int j=0;j<n;++j){
                if( i >> j & 1 ){
                    ++cnt;
                    sum += b[j];
                }
            }
            
            int idx = lower_bound(mp[n-cnt].begin(),mp[n-cnt].end(),(all/2)-sum) - mp[n-cnt].begin();
            for(int j=-1;j<=+1;++j){
                if( idx + j >= 0 && idx + j < mp[n-cnt].size() ){
                    ans = min(ans, abs(all - 2*(sum + mp[n-cnt][idx+j])) );
                }
            }
            
        }
        return ans;
        
    }
};
