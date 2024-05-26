class Solution {
public:
    int minOperations(vector<vector<int>>& g, int x) {
        int rem = -1;
        int n = g.size(), m = g[0].size();
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if( rem != -1 && rem != g[i][j] % x )
                    return -1;
                rem = g[i][j] % x;
            }
        }
        vector<int>arr;
        long long rsum = 0, lsum = 0, ans = 1e18;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                arr.push_back(g[i][j]);
                rsum += g[i][j];
            }
        }
        sort(arr.begin(),arr.end());
        int N = n * m;
        for(int i=0;i<N;++i){
            long long cnt = 1ll * arr[i] * i - lsum + rsum - 1ll * (N-i) * arr[i];
            
            lsum += arr[i];
            rsum -= arr[i];
            
            ans = min(ans,cnt);
            
            
        }
        return ans/x;
        
    }
};
