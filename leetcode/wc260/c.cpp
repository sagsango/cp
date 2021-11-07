class Solution {
public:
    bool placeWordInCrossword(vector<vector<char>>& g, string word){
        int n = g.size(), m = g[0].size(), k = word.length();
        vector<vector<int>>h(n,vector<int>(m)),v(n,vector<int>(m));
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                h[i][j] = (g[i][j]=='#') + (j?h[i][j-1]:0);
                v[i][j] = (g[i][j]=='#') + (i?v[i-1][j]:0);
            }
        }
        for(int i=0;i<n;++i){
            for(int j=0;j+k<=m;++j){
                if( h[i][j+k-1] - (j?h[i][j-1]:0) == 0 &&
                    (j == 0 || g[i][j-1] == '#') &&
                    (j+k==m || g[i][j+k] == '#')  ){
                    
                    int l = 0, ok = 1;
                    for(int l=0;l<k && ok;++l){
                        ok &= g[i][j+l] == ' ' || g[i][j+l] == word[l];
                    }
                    if( ok )
                        return true;
                    
                    
                    l = 0, ok = 1;
                    for(int l=0;l<k && ok;++l){
                        ok &= g[i][j+k-1-l] == ' ' || g[i][j+k-1-l] == word[l];
                    }
                    if( ok )
                        return true;
                }
            }
        }
        for(int j=0;j<m;++j){
            for(int i=0;i+k<=n;++i){
                if( v[i+k-1][j] - (i?v[i-1][j]:0) == 0 &&
                    (i == 0 || g[i-1][j] == '#' ) &&
                    (i+k==n || g[i+k][j] == '#') ){
                    
                    int l = 0, ok = 1;
                    for(int l=0;l<k && ok;++l){
                        ok &= g[i+l][j] == ' ' || g[i+l][j] == word[l];
                    }
                    if( ok )
                        return true;
                    
                    
                    l = 0, ok = 1;
                    for(int l=0;l<k && ok;++l){
                        ok &= g[i+k-1-l][j] == ' ' || g[i+k-1-l][j] == word[l];
                    }
                    if(ok )
                        return true;
                }
                   
            }
        }
        return false;
    }
};
