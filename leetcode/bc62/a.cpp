class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if( n * m != original.size() )
            return {};
        swap(n,m);
        vector<vector<int>>arr(n,vector<int>(m));
        for(int i=0;i<n*m;++i){
            int r = i / m;
            int c = i % m;
            arr[r][c] = original[i];
        }
        return arr;
        
    }
};
