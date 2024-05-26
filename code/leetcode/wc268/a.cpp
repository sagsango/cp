class Solution {
public:
    int maxDistance(vector<int>& arr){
       int l, r, mx = 0, n = arr.size();
        
        l = 0, r = n-1;
        while( r >= 0 && arr[l] == arr[r] )
            --r;
        
        mx = max(mx, r-l);
        
        l = 0, r = n-1;
        while( r < n && arr[l] == arr[r] )
            ++l;
        
        mx = max(mx, r-l);
        
        return mx;
    }
};
