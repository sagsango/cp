class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>HashMap;
        int same = 0, count = 0;
        for(auto &word:words){
            HashMap[word] += 1;
        }
        for(auto &word:words){
            if( HashMap[word] == 0 )
                continue;
            assert( word.length() == 2u );
            HashMap[word] -= 1;
            string key(2,'\0');
            key[0] = word[1];
            key[1] = word[0];
            //cout << word <<" "<< key << endl;
            if( HashMap.find(key) != HashMap.end() && HashMap[key] != 0 ){
                HashMap[key] -= 1;
                count += 4;
            }else if( word[0] == word[1] ){
                same++;
            }
        }
        return count + min(2,same*2);
        
        
    }
};
