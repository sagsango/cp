class Solution {
public:
    int minimumSum(int num) {
        int sum = INT_MAX;
        vector<int>arr;
        for(int i=0;i<4;++i){
            arr.push_back(num%10);
            num /= 10;
        }
        sort(arr.begin(),arr.end());
        do{
            int num1 = arr[0] * 10 + arr[1];
            int num2 = arr[2] * 10 + arr[3];
            sum = min(sum, num1 + num2 );
            
        }while( next_permutation(arr.begin(),arr.end()));
        return sum;
    }
};
