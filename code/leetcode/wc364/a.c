class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int cnt[2] = {0,0};
        for(auto &c:s){
            cnt[c-'0'] += 1;
        }
        int i = 0;
        string ans = s;
        while( cnt[1] > 1){
            ans[i] = '1';
            cnt[1] -= 1;
            i += 1;
        }
        while( cnt[0] > 0){
            ans[i] = '0';
            cnt[0] -= 1;
            i += 1;
        }
        ans[i] = '1';
        return ans;
        
        
    }
};
