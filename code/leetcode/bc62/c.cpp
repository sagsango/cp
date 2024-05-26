class Solution {
public:
    int solve(string s,int k,char c){
        int ans = 0, cnt = 0, j=0, n = s.length();
        for(int i=0;i<n;++i){
            while( j < n && (cnt + (s[j] == c) ) <= k ){
                cnt += s[j] == c;
                ++j;
            }
            ans = max(ans,j-i);
            cnt -= s[i] == c;
        }
        return ans;
    }
    int maxConsecutiveAnswers(string answerKey, int k){
        return max( solve(answerKey,k,'T'), solve(answerKey,k,'F'));
        
    }
};
