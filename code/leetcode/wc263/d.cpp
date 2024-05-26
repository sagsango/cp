class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change){
        vector<int>dis(2*n,1e9);
        vector<int>g[2*n];
        int m = edges.size();
        for(int i=0;i<m;++i){
            int u = edges[i][0] - 1, v = edges[i][1] - 1;
            g[u<<1|0].push_back(v<<1|1);
            g[u<<1|1].push_back(v<<1|0);
            g[v<<1|0].push_back(u<<1|1);
            g[v<<1|1].push_back(u<<1|0);
        }
        queue<int>q;
        dis[0]=0;
        q.push(0);
        while( q.size() ){
            int u = q.front(); 
            q.pop();
            for(auto v:g[u]){
                if( dis[v] > dis[u] + 1 ){
                    dis[v] = dis[u] + 1;
                    q.push(v);
                }
            }
        }
        
        function<int(int)> total_time = [&](int n){
            if( n == 1e9 )
                return (int)1e9;
            int cur_time = 0;
            for(int i=0;i<n;++i){
                int p = cur_time/change;
                int r = cur_time%change;
                if( p & 1 ){
                    cur_time = ( p + 1 ) * change;
                }
                cur_time += time;
            }
            return cur_time;
        };
        
        
       
        int s = n-1;
        set<int>st;
        if( dis[s<<1|0] != 1e9 ){
            st.insert(total_time(dis[s<<1|0]));
            st.insert(total_time(dis[s<<1|0]+2));
        }
        if(dis[s<<1|1] != 1e9 ){
            st.insert(total_time(dis[s<<1|1]));
            st.insert(total_time(dis[s<<1|1]+2));
        }
        return *(++st.begin());
        
    }
};
