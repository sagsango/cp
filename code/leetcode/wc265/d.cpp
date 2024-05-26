// TODO: use iterative solution
class Solution {
    unordered_map<int,unordered_map<int,unordered_map<int,int>>>dp;
    //map<int,map<int,map<int,int>>>dp;
public:
    bool solve(string &s1, string &s2,int dLen, int idx1, int idx2){
        if( idx1 == s1.length()  && idx2 == s2.length() )
            return dLen == 0;
        if( dp[dLen][idx1].find(idx2) !=  dp[dLen][idx1].end() ){
            return dp[dLen][idx1][idx2];
        }
        dp[dLen][idx1][idx2] = false;
        if( idx1 < s1.length() && 
            idx2 < s2.length() && 
            'a' <= s1[idx1]  && s1[idx1] <= 'z' &&
            'a' <= s2[idx2]  && s2[idx2] <= 'z' &&
             dLen == 0 ){
            return dp[dLen][idx1][idx2] = s1[idx1] == s2[idx2] && solve(s1,s2,dLen,idx1+1,idx2+1);
        }
        if( idx1 < s1.length() && 'a' <= s1[idx1]  && s1[idx1] <= 'z' && dLen > 0 ){
            if( solve(s1,s2,dLen-1,idx1+1,idx2) ){
                 return dp[dLen][idx1][idx2] = true;
            }
        }else{
            int len = 0, i = idx1;
            while( i < s1.length() && '0' <= s1[i]  && s1[i] <= '9' ){
                len = len * 10 + s1[i] -'0';
                if( solve(s1,s2,dLen-len,i+1,idx2) ){
                    return dp[dLen][idx1][idx2] = true;
                }
                ++i;
            }
        }
        
        if( idx2 < s2.length() && 'a' <= s2[idx2]  && s2[idx2] <= 'z' && dLen < 0 ){
            if( solve(s1,s2,dLen+1,idx1,idx2+1) ){
                 return dp[dLen][idx1][idx2] = true;
            }
        }else{
            int len = 0, i = idx2;
            while( i < s2.length() && '0' <= s2[i]  &&  s2[i] <= '9' ){
                len = len * 10 + s2[i] -'0';
                if( solve(s1,s2,dLen+len,idx1,i+1) ){
                    return dp[dLen][idx1][idx2] = true;
                }
                ++i;
            }
        }
        return false;
        
    }
    bool possiblyEquals(string S1, string S2) {
        string s1 = S1;
        string s2 = S2;
        return solve(s1,s2,0,0,0);
       
        
    }
};
