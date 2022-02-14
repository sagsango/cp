class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.length();
        auto val = [&](int i){
            return i < n ? s[i] : fill;
        };
        int m = ( n + k - 1 ) / k;
        vector<string>ans(m);
        for(int i=0;i<m;++i){
            for(int j=k*i;j<(i+1)*k;++j){
                ans[i] += val(j);
            }
        }
        return ans;
        
        
    }
};
