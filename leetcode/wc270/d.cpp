class Solution {
    unordered_map<int,vector<pair<int,int>>>g;
    vector<vector<int>>edg;
    unordered_set<int>vis;
    unordered_map<int,int>top;
    vector<vector<int>>order;
    unordered_map<int,int> Degree;
    int start;
    void dfs(int u, int idx=-1){
        while( top[u] < g[u].size() ){
            int v = g[u][top[u]].first;
            int i = g[u][top[u]].second;
            ++top[u];
            if( !vis.count(i) ){
                vis.insert(i);
                dfs(v,i);
            }
        }
        if( idx != -1 ){
             order.emplace_back(edg[idx]);
        }
    }
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs){
        edg = pairs, g.clear(), vis.clear(),top.clear(),order.clear(),Degree.clear();
        for(int i=0;i<edg.size();++i){
            int u = edg[i][0], v = edg[i][1];
            g[u].push_back({v,i});
            Degree[u] += 1;
            Degree[v] -= 1;
        }
        start = edg[0][0];
        for(auto &it:g){
            int u = it.first;
            if( Degree[u] > 0 ){
                start = u;
            }
        }
        dfs(start);
        reverse(order.begin(),order.end());
        return order;
    }
};
