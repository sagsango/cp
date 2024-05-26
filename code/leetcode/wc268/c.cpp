class RangeFreqQuery {
    unordered_map<int,vector<int>>mp;
public:
    RangeFreqQuery(vector<int>& arr) {
        for(int i=0;i<arr.size();++i){
            mp[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int val) {
        int ans = 0;
        if( mp.find(val) != mp.end() ){
            ans += upper_bound(mp[val].begin(),mp[val].end(),right) - lower_bound(mp[val].begin(),mp[val].end(),left);
        }
        return ans;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
