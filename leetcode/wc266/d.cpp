


class Solution {
    vector<vector<pair<int,int>>>g;
    vector<int>vis, coin;
    int maxLen, len, sum, maxSum, n, m;
public:
    void dfs(int u){
        if( vis[u] == 0 ){
            sum += coin[u];
        }
        vis[u] += 1;
        
        if( u == 0 ){
            maxSum = max(maxSum, sum);
        }
        for(auto [v,w]:g[u]){
            if( w + len <= maxLen ){
                len += w;
                dfs(v);
                len -= w;
            }
        }
        vis[u] -= 1;  
        if( vis[u] == 0 ){
            sum -= coin[u];
        }
    }
    
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        
        // maximum 10 edges you can traverse.
        // (4 ^ 10) => just fo dfs 
        // means brute force.
        
        
        n = values.size(), m = edges.size();
        g = vector<vector<pair<int,int>>>(n);
        vis  = vector<int>(n);
        coin = values;
        for(int i=0;i<m;++i){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            g[u].push_back({v,w});
            g[v].push_back({u,w});
        }
        
        maxLen = maxTime, len = maxSum = sum = 0;
        dfs(0);
        return maxSum;
        
       
        
        
        
    }
};
