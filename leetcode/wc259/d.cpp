class Solution {
public:
    string longestSubsequenceRepeatedK(string s, int k){
        unordered_map<char,int>mp;
        for(auto x:s){
            mp[x] += 1;
        }
        string tmp;
        for(auto [c,f]:mp){
            int x =  f / k;
            while( x -- ){
                tmp += c;
            }
        }
        string ans;
        sort(tmp.begin(),tmp.end());
        int n = tmp.size();
        unordered_set<string>vis;
        for(int i=1;i<1<<n;++i){
            string cur;
            for(int j=0;j<n;++j){
                if( i >> j & 1 ){
                    cur += tmp[j];
                
                }
            }
            if( vis.count(cur ) )
                continue;
            vis.insert(cur);
            do{
                int cnt = 0, j = 0;
                for(int k=0;k<s.length();++k){
                    if( cur[j] == s[k] ){
                        ++j;
                    }
                    if( j == cur.size() ){
                        ++cnt;
                        j = 0;
                    }
                }
                if( cnt >= k && ( cur.length() > ans.length() || ( cur.length() == ans.length() && cur > ans) ) ){
                    ans = cur;
                }
            }while( next_permutation(cur.begin(),cur.end()));
        }
        return ans;
    }
};
