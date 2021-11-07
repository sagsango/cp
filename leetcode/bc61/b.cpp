class Solution {
public:
    vector<int>findOriginalArray(vector<int>& changed){
        sort(changed.begin(),changed.end());
        unordered_map<int,int>hashMap;
        vector<int>original;
        for(auto x:changed){
            hashMap[x] += 1;
        }
        int n = changed.size();
        for(int i=n-1;i>=0;--i){
            if( hashMap[changed[i]] > 0 ){
                 hashMap[changed[i]] -= 1;
                if( changed[i] % 2 || hashMap[changed[i]/2] == 0 ){
                    original.clear();
                    return original;
                }
                hashMap[changed[i]/2] -= 1;
                original.push_back(changed[i]/2);
            }
        }
        return original;
        
        
    }
};
