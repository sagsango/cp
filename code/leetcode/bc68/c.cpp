class Solution {
public:
    bool canBeValid(string s, string locked) {
        if( s.length() & 1 )
            return false;
        
        int depthMax = 0, depthMin = 0;
        for(int i=0;i<s.length();++i){
            if( locked[i] == '1' ){
                if( s[i] == '('){
                    depthMax += 1;
                    depthMin += 1;
                }else{
                    depthMax -= 1;
                    depthMin -= 1;
                }
            }else{
                depthMax += 1;
                depthMin -= 1;
            }
            depthMin = max(depthMin,0);
            if( depthMax < 0 )
                return false;
          
        }
        if( depthMin > 0 )
            return false;
        return true;
       
        
    }
};
