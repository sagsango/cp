class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int>start_time(n);
        vector<int>in_degree(n), out_degree(n);
        vector<int>graph[n];
        int m = relations.size();
        for(int i=0;i<m;++i){
            int u = relations[i][0] - 1, v = relations[i][1] -1;
            in_degree[v] += 1;
            out_degree[u] += 1;
            graph[u].push_back(v);
        }
        queue<int>q;
        for(int i=0;i<n;++i){
            if( in_degree[i] == 0 ){
                q.push(i);
            }
        }
        while( q.size() ){
            int u = q.front();
            q.pop();
            for(auto v:graph[u]){
                in_degree[v] -= 1;
                start_time[v] = max(start_time[v], start_time[u] + time[u]);
                if( in_degree[v] == 0 ){
                    q.push(v);
                }
            }
        }
        int end_time = 0;
        for(int i=0;i<n;++i){
            if( out_degree[i] == 0 ){
                end_time = max( end_time, start_time[i] + time[i] );
            }
        }
        return end_time;
        
    }
};
