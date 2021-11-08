class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size(), ans = 0;
        vector<int>g[n],h(n),vis(n);
        for(auto arr:edges){
            int u = arr[0], v = arr[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        queue<int>q;
        q.push(0);
        vis[0] = 1;
        while( !q.empty() ){
            int u = q.front(), leaf = 1;
            q.pop();
            for(auto v:g[u]){
                if( !vis[v] ){
                    h[v] = h[u] + 1;
                    q.push(v);
                    vis[v] = 1;
                    leaf = 0;
                }
            }
            if( leaf ){// leaf
                int k = (2*h[u]-1)/patience[u];
                int t = k * patience[u] + 2*h[u];
                ans = max(ans,t);
            }
        }
        return ans+1;
        
    }
};
