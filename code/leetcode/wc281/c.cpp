class Solution {
public:
    string repeatLimitedString(string str, int lim) {
        vector<int>cnt(26);
        for (auto c: str){
            cnt[c-'a'] += 1;
        }
        string s;
        
        int last = -1;
        while (true)
        {
            start:
            int bigger = -1;
            for(int i = 25; i>= 0; --i){
                if(cnt[i]){
                    bigger = i;
                    break;
                }
            }
            
            for(int i=25; i>=0; --i){
                if(cnt[i] && last != i){
                    int x = bigger > i ? 1 : lim;
                    int y = min(x,cnt[i]);
                    
                    cnt[i] -= y;
                    while(y--){
                        s += 'a' + i;
                    }
                    last = i;
                    goto
                        start;
                }
            }
            break;
        }
        return s;
    }
};
