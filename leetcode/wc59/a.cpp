class Solution {
public:
    int minTimeToType(string word) {
        int i = 0, cnt = 0;
        for(auto c:word){
            int j = c - 'a';
            cnt += 1 + min(abs(i-j),26-abs(i-j));
            i = j;
        }
        return cnt;
        
    }
};
