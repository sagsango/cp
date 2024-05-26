class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        auto cmp = [&](const vector<int> &a,const vector<int>&b){
            if( a[0] != b[0] ){
                return a[0] < b[0];
            }
            return a[1] < b[1];
        };
        sort(properties.begin(),properties.end(),cmp);
        int mx_val = INT_MIN, cnt = 0, n = properties.size(), idx = n;
        for(int i=n-1;i>=0;--i){
            while( idx > i && properties[idx-1][0] > properties[i][0] ){
                mx_val = max(mx_val, properties[--idx][1]);
            }
            if( properties[i][1] < mx_val  ){
                ++cnt;
            }
        }
        return cnt;
        
    }
};
