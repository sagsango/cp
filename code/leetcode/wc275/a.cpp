class Solution {
public:
    bool checkValid(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        for(int i=0;i<n;++i){
            unordered_set<int>st;
            for(int j=0;j<m;++j){
                if( mat[i][j] < 1 || mat[i][j] > n || st.count(mat[i][j]) ){
                    return false;
                }
                st.insert(mat[i][j]);
            }
        }
        for(int j=0;j<m;++j){
            unordered_set<int>st;
            for(int i=0;i<n;++i){
                if( mat[i][j] < 1 || mat[i][j] > n || st.count(mat[i][j]) ){
                    return false;
                }
                st.insert(mat[i][j]);
            }
        }
        return true;
        
    }
};
