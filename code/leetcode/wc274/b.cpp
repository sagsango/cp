class Solution {
public:
    #define EMPTY 0
    int numberOfBeams(vector<string>& bank){
        int total_beams = 0, total_device_in_last_non_empty_row = 0;
        int bank_rows = bank.size(), bank_cols = bank[0].size();
        
        for(int row = 0; row < bank_rows; ++row){
            int device_in_cur_row = 0;
            for(int col = 0; col < bank_cols; ++col){
                if( bank[row][col] == '1' ){
                    device_in_cur_row += 1;
                    total_beams += total_device_in_last_non_empty_row;
                }
            }
            if( device_in_cur_row != EMPTY ){
                total_device_in_last_non_empty_row = device_in_cur_row;
            }
        }
        
        return total_beams;
        
    }
};
