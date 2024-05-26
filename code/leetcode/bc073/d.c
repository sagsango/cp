class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int cost = 0;
        while (s.length()){
            int n = s.length();
            int r = n-1;
            while(s[r] != s[0]){
                --r;
            }
            int x = n-1-r;
            
            int l = 0;
            while(s[l] != s[n-1]){
                ++l;
            }
            int y = l;
            
            if(x<y){
                /* [1,r-1] + [r+1,n-1] */
                s = s.substr(1,r-1-1+1) + s.substr(r+1,n-1-r-1+1);
                cost += x;
            }else{
                /* [0,l-1] + [l+1,n-2] */
                s = s.substr(0,l-1-0+1) + s.substr(l+1,n-2-l-1+1);
                cost += y;
            }
        }
        return cost;
        
    }
};
