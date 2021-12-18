class Solution {
public:
    int solve(vector<int>&arr){
        int n = arr.size();
        vector<int>l(n),r(n);
        for(int i=0;i<n;++i){
            l[i] = min(arr[i],i!=0?l[i-1]+1:1);
        }
        for(int i=n-1;i>=0;--i){
            r[i] = min(arr[i],i!=n-1?r[i+1]+1:1);
        }
        int ans = 0;
        for(int i=0;i<n;++i){
            int x = min(l[i],r[i]);
            if( x > 1 ){
                ans += x - 1;
            }
        }
        return ans;
    }
    int countPyramids(vector<vector<int>>& g){
        int n = g.size(), m = g[0].size(), ans = 0;
        vector<vector<int>>u(n,vector<int>(m)),d(n,vector<int>(m));
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if( g[i][j] ){
                    u[i][j] = 1 + (i!=0?u[i-1][j]:0);
                }
            }
        }
        for(int i=n-1;i>=0;--i){
            for(int j=0;j<m;++j){
                if( g[i][j] ){
                    d[i][j] = 1 + (i!=n-1?d[i+1][j]:0);
                }
            }
        }
        for(int i=0;i<n;++i){
            ans += solve(d[i]);
            //cout << i <<":" <<" "<< solve(u[i]) <<" "<< solve(d[i]) << endl;
            ans += solve(u[i]);
        }
        return ans;
        
    }
};
