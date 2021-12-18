class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits){
        sort(digits.begin(),digits.end());
        vector<int>nums;
        int n = digits.size();
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                for(int k=0;k<n;++k){
                    if( i != j && i != k && j != k && digits[i] != 0 && digits[k] % 2 == 0 ){
                        nums.push_back(digits[i]*100+digits[j]*10+digits[k]);
                    }
                }
            }
        }
        sort(nums.begin(),nums.end());
        nums.erase(unique(nums.begin(),nums.end()),nums.end());
        return nums;
        
        
        
    }
};
