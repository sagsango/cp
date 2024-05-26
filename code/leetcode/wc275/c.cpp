
class Solution {
    int Mask(string &s){
        int msk = 0;
        for(auto &c:s){
            msk |= 1LL << (c - 'a');
        }
        return msk;
    }
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords){
        unordered_set<int>st;
        for(auto &word:startWords){
            st.insert(Mask(word));
        }
        int cnt = 0;
        for(auto &word:targetWords){
            int msk = Mask(word);
            int ok = 0;//st.count(msk);
            for(int i=0;i<26;++i){
                if( msk >> i & 1 ){
                    ok |= st.count(msk ^ ( 1<<i) );
                }
            }
            cnt += ok;
        }
        return cnt;
        
    }
};
