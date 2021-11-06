class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& arr) {
        
        auto cmp = [&](vector<int> & a, vector<int> & b ){
            if( a[0] != b[0] )
                return a[0] < b[0];
            return a[1] < b[1];
        };
        
        sort(arr.begin(),arr.end(),cmp);
        
        int n = arr.size(), cnt = 0, mx = 0, j = n-1;
        const int mod =1e9+7;
        vector<int>dp(n);
        while( j >= 0 ){
            int tmx = mx, k = j;
            while( k >= 0 && arr[j][0] == arr[k][0] ){
                tmx = max(tmx, arr[k][1]);
                dp[k] = mx;
                --k;
            }
            mx = tmx;
            j = k;
        }
        
        for(int i=0;i<n;++i){
            cnt += dp[i] > arr[i][1];
        }
        return cnt;
        
    }
};
