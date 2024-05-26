class Solution {
public:
    long long countVowels(string s) {
        // hard to calculate how many vovels are there in evey substring
        // easy to calculae, this vovel will be counted in how many substrings
    
        long long cnt = 0, n = s.length();
        for(int i=0;i<n;++i){
            if( s[i] == 'a' ||
              s[i] == 'e' ||
              s[i] == 'i' ||
              s[i] == 'o' ||
              s[i] == 'u' ){
                cnt += (i+1) * ( n - i );
            }
        }
        
        return cnt;
        
    }
};
