class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& arr) {
        int i = 0;
        long long num;
        vector<int>ans;
        while (i<arr.size()){
            num = arr[i++];
            while(i<arr.size() && gcd(num,arr[i]) != 1){
                num = (num*arr[i])/gcd(num,arr[i]);
                ++i;
            }
            while(ans.size() && gcd(ans[ans.size()-1],num) != 1){
                num = (ans[ans.size()-1]*num)/gcd(ans[ans.size()-1],num);
                ans.pop_back();
            }
            ans.push_back(num);
        }
        return ans;
        
    }
};
