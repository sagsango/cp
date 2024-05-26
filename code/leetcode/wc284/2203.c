class Solution {
    struct node{
        long long dis;
        int u;
        bool operator<(const struct node &other)const{
            return dis > other.dis;
        }
    };
    vector<long long> dijkstra(int s,int n, vector<vector<pair<int,int>>>&g){
        vector<long long> dis(n,1e17);
        vector<bool> vis(n);
        priority_queue<node> pq;
        dis[s] = 0;
        pq.push({dis[s], s});
        while (!pq.empty()){
            int u = pq.top().u;
            pq.pop();
            if (vis[u])
                continue;
            vis[u] = 1;
            for(auto [v,w]:g[u]){
                if(dis[v] > dis[u] + w){
                    dis[v] = dis[u] + w;
                    pq.push({dis[v],v});
                }
            }
        }
        return dis;
    }
public:
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        
        vector<vector<pair<int,int>>>g(n), gr(n);
        
        for(auto &edge:edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            g[u].push_back({v,w});
            gr[v].push_back({u,w});
        }
        
        auto d_src1 = dijkstra(src1, n, g);
        auto d_src2 = dijkstra(src2, n, g);
        auto d_dest = dijkstra(dest, n, gr);
        
        long long ans = 1e17;
        for(int u=0; u<n; ++u){
            ans = min(ans, d_src1[u] + d_src2[u] + d_dest[u]);
        }
        
        return ans < 1e17 ? ans : -1;
    }
};
