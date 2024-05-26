struct box{
        long long distance;
        int price, row, col;
        box(long long distance, int price, int row, int col):distance(distance),price(price),row(row),col(col){
            //distance = LONG_MAX, price = row = col = INT_MAX;
        }
        bool operator<(const box &other){
            if( distance != other.distance ){
                return distance < other.distance;
            }
            if( price != other.price ){
                return price < other.price;
            }
            if( row != other.row ){
                return row < other.row;
            }
            return col < other.col;
        }
    };
 
const int dx[4] = {+1,-1,+0,-0};
const int dy[4] = {+0,-0,+1,-1};
class Solution {
   
public:
    bool valid(int x,int y, int n, int m){
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        if( grid.empty() ){
            return {};
        }
        vector<box>arr;
        int n = grid.size(), m = grid[0].size();
        queue<vector<int>>q;
        vector<vector<int>>vis(n,vector<int>(m));
        vector<vector<long long>> dis(n,vector<long long>(m,INT_MAX));
        vis[start[0]][start[1]] = 1;
        dis[start[0]][start[1]] = 0;
        q.push(start);
        while( q.size() ){
            vector<int> cell = q.front();
            q.pop();
            if( grid[cell[0]][cell[1]] != 1 && pricing[0] <= grid[cell[0]][cell[1]] && grid[cell[0]][cell[1]] <= pricing[1]){
                arr.push_back({dis[cell[0]][cell[1]], grid[cell[0]][cell[1]], cell[0], cell[1]});
            }
            for(int i=0;i<4;++i){
                int x = cell[0] + dx[i];
                int y = cell[1] + dy[i];
                if( valid(x,y,n,m) && grid[x][y] && !vis[x][y] ){
                    vis[x][y] = 1, dis[x][y] = 1 + dis[cell[0]][cell[1]];
                    q.push({x,y});
                }
            }
        }
        sort(arr.begin(),arr.end());
        vector<vector<int>>ans;
        for(int i=0;i<arr.size() && i < k;++i){
            vector<int>cell(2);
            cell[0] = arr[i].row;
            cell[1] = arr[i].col;
            ans.emplace_back(cell);
        }
        return ans;
        
        
    }
};
