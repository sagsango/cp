class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        long long l[2][n], r[2][n];
        
        l[0][0] = grid[0][0];
        l[1][0] = grid[1][0];
        
        for(int i=1;i<n;++i){
            for(int j=0;j<2;++j){
                l[j][i] = l[j][i-1] + grid[j][i];
            }
        }
        
        r[0][n-1] = grid[0][n-1];
        r[1][n-1] = grid[1][n-1];
        
        for(int i=n-2;i>=0;--i){
            for(int j=0;j<2;++j){
                r[j][i] = r[j][i+1] + grid[j][i];
            }
        }
        
        long long mx_sum = 1e18;
        for(int i=0;i<n;++i){
            mx_sum = min( 1.00 * mx_sum, max(i?l[1][i-1]:-1e18,i+1<n?r[0][i+1]:-1e18));
        }
        
        return max(mx_sum,0ll);
        
    }
};
