class Solution {
public:
    vector<int> groupStrings(vector<string>& words){
        // missing -> ith unset => mask ^ (1<<i)
        // extra -> ith set => mask ^ (1<<i)
        // replacement -> ithset & jth unset.
        
        // O(n*26*26)
        
        
    }
};
