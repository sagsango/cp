class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string& s) {
        int m = s.length();
        function<bool(int,int,int)> valid = [&](int i,int x,int y){
            if( i < 0 || x < 0 || y < 0 ||
                i >= m || x >= n || y >= n )
                return false;
            return true;
        };
        function<int(int,int,int)> move_ = [&](int i, int x,int y){
            if( i >= m )
                return 0;
            int new_x = x, new_y = y;
            switch(s[i]){
                case 'L':
                    new_y -= 1; 
                    break;
                case 'R':
                    new_y += 1;
                    break;
                case 'U':
                    new_x -= 1;
                    break;
                case 'D':
                    new_x += 1;
                    break;
                default:
                    assert(false);   
            }
            if( !valid(i,new_x,new_y) )
                return 0;
            return 1 + move_(i+1,new_x,new_y);
            
        };
        vector<int>path_len(m);
        for(int i=0;i<m;++i){
            path_len[i] = move_(i,startPos[0],startPos[1]);
        }
        return path_len;
        
    }
};
