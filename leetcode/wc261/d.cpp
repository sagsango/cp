
const int nax = 5e4+10;
int dp[nax][26], ct[nax][26];
class Solution {
public:
    string smallestSubsequence(string s, int k, char letter, int repetition) {
        int n = s.length();
        for(int i=0;i<26;++i){
            dp[n][i] = ct[n][i] = 0;
        }
        //vector<vector<int>>dp(n+1,vector<int>(26));
        //vector<vector<int>>ct(n+1,vector<int>(26));
        // dp[cur_length][next charecter needed ] = which min length have to travers to get that lettter
        // ct[cur_length][charecter ] = how many charecter are there in indx such thst indx > cur_len. 
        for(int i=n-1;i>=0;--i){
            for(int j=0;j<26;++j){
                dp[i][j] = dp[i+1][j];
                ct[i][j] = ct[i+1][j];
            }
            dp[i][s[i]-'a'] = i+1;
            ct[i][s[i]-'a'] += 1;
        }
        string ans(k,'\0');
        int idx = 0, len = 0;
        while( idx < n && k){
            for(int i=0;i<26;++i){
                int nxt_idx = dp[idx][i];
                int req_len = k - 1;
                int req_rep = repetition - ( i + 'a' == letter );
                if( nxt_idx && ct[nxt_idx][letter-'a'] >= req_rep && n - nxt_idx >= req_len && req_rep <= req_len){
                    ans[len++] = (char)(i+'a');
                    repetition -= ( i + 'a' == letter );
                    k -= 1;
                    idx = nxt_idx;
                    break;
                }
            }
        }
        return ans;
        
    }
};
