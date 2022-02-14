class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        // 101
        
        // 10011
        
        // 1010
        
        int max_bit = 0;
        for(int i=0;i<32;++i){
            if( target >> i & 1 ){
                max_bit = i;
            }
        }
        int k = min(max_bit-1,maxDoubles-1);
        int cost = 0, nums = 0;
        for(int i=k+1;i<=max_bit;++i){
            nums += ( target >> i & 1 ) << (i - (k+1));
        }
        for(int i=0;i<=k;++i){
            cost += target >> i & 1;
        }
        //cout << max_bit <<" "<< nums << endl;
        cost += nums + k;
        return cost;
        
        
    }
};
