class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums){
        int n = nums.size();
        vector<int>alive(1<<n);
        for(auto s:nums){
            int msk = 0;
            for(int i=0;i<n;++i){
                cout << s << endl;
                msk ^= (1<<i) * ( s[i] -'0' );
            }
            alive[msk] = 1;
        }
        for(int i=0;i<1<<n;++i){
            if( !alive[i] ){
                string s; 
                for(int j=0;j<n;++j){
                    s += (i>>j&1) + '0';
                }
                cout << s << endl;
                return s;
            }
        }
        return "-1";
    }
};
