class Solution {
    const int dx[4] = {+1,-1,+0,-0};
    const int dy[4] = {+0,-0,+1,-1};
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size(), m = land[0].size();
        vector<vector<int>>vis(n,vector<int>(m)),ans;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if( land[i][j] && !vis[i][j]){
                    pair<int,int> l, r;
                    l = {1e9,1e9}, r = {-1e9,-1e9};
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    vis[i][j] = 1;
                    while( q.size() ){
                        pair<int,int> u = q.front();
                        q.pop();
                        if( l > u )
                            l = u;
                        if( r < u )
                            r = u;
                        for(int k=0;k<4;++k){
                            int x = u.first + dx[k], y = u.second + dy[k];
                            if( x >= 0 && x < n && y >= 0 && y < m && land[x][y] && !vis[x][y] ){
                                vis[x][y] = 1;
                                q.push({x,y});
                            }
                        }
                    }
                    vector<int>tmp = {l.first,l.second,r.first,r.second};
                    ans.emplace_back(tmp);
                }
            }
        }
        return ans;
    }
};
