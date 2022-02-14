class Solution {
public:
    int maximumGood(vector<vector<int>>& statements){
        int n = statements.size(), mx_good = 0;
        for(int msk=0;msk<1<<n;++msk){
            int good = msk;
            int bad = ( (1<<n) - 1 ) ^ good;
            bool ok = 1;
            for(int i=0;i<n && ok;++i){
                if( good >> i & 1 ){
                    for(int j=0;j<n && ok;++j){
                        if( statements[i][j] == 0 && !( bad >> j & 1 ) )
                            ok = 0;
                        if( statements[i][j] == 1 && !( good >>j & 1 ) )
                            ok = 0;
                    }
                }
            }
            if( ok )
                mx_good = max(mx_good, __builtin_popcount(good));
        }
        return mx_good;
    }
};
