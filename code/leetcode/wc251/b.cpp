class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        int i = 0, n = num.length();
        while( i < n && change[num[i]-'0'] <= num[i]-'0')
            ++i;
        while( i < n && change[num[i]-'0'] >= num[i]-'0'){
            num[i] = change[num[i]-'0'] + '0';
            ++i;
        }
        return num;
        
    }
};
