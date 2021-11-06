class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        map< pair<int,int>, int > mp;
        long long ans = 0;
        for(auto v:rectangles){
            int g = gcd(v[0],v[1]);
            ans += mp[{v[0]/g,v[1]/g}];
            mp[{v[0]/g,v[1]/g}]++;
            
        }
        return ans;
        
    }
};
