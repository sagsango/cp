class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        long long mn = 1e9, ng = 0, zero = 0, sum = 0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                mn = min(mn,1ll*abs(mat[i][j]));
                sum += abs(mat[i][j]);
                ng += mat[i][j] < 0 ;
                zero += mat[i][j] == 0;
            }
        }
        if( !zero && ng % 2 )
            sum -= 2*mn;
        return sum;
        
    }
};
