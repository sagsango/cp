class Solution {
public:
    typedef long long ll;
    const int mod = 1e9+7;
    int add(int a,int b){
        return (a+b) % mod;
    }
    priority_queue< pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>> >pq;
    vector<ll> dijkstra(int s,vector<vector<pair<ll,ll>>>&g){
        int n = g.size();
        vector<ll>dis(n,1e18),vis(n,0);
        dis[s] = 0;
        pq.push({dis[s],s});
        while( ! pq.empty() ){
            int u = pq.top().second;
            pq.pop();
            if( vis[u] ){
                continue;
            }
            vis[u] = 1;
            for(auto [v,w]:g[u]){
                if( dis[v] > dis[u] + w ){
                    dis[v] = dis[u] + w;
                    pq.push({dis[v],v});
                }
            }
        }
        return dis;
    }
    
    int solve(vector<ll>&ds, vector<ll>&dt, vector<vector<pair<ll,ll>>>&g){
        int n = g.size();
        vector<ll>dp(n),vis(n);
        dp[0] = 1;
        pq.push({ds[0],0});
        while( ! pq.empty() ){
            int u = pq.top().second;
             pq.pop();
            if( vis[u] ){
                continue;
            }
            vis[u] = 1;
            //cout << u << " ";
            for(auto [v,w]:g[u]){
                if( ds[u] + w + dt[v] == ds[n-1]){
                    dp[v] = add(dp[v],dp[u]);
                    pq.push({ds[v],v});
                }
            }
        }
        return dp[n-1];
    }
    
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<ll,ll>>> g(n);
        for(auto v:roads){
            g[v[0]].push_back({v[1],v[2]});
            g[v[1]].push_back({v[0],v[2]});
        }
        vector<ll>ds = dijkstra(0,g);
        vector<ll>dt = dijkstra(n-1,g);
        return solve(ds,dt,g);
        
    }
};
