/*You are given a AB character matrix named C. Every cell in C has a character U,R,L or D indicating up,right,left and down.
	Your target is to go from top left corner to the bottom right corner of the matrix.
	But there are some restrictions while moving along the matrix:
	If you follow what is written in the cell then you can move freely.
	But if you don't follow what is written in the cell then you have to pay 1 unit of cost.
	Like: If a cell contains character U and you go right instead of Up you have to pay 1 unit of cost.
	So your task is to find the minimum c
 */






#define NOT_REACHABLE -1

struct node{
    int x, y, d;
    node(int x,int y,int d):x(x),y(y),d(d){}
};

// according to the direction dx, dy represent the move
const string direction = "UDLR";
const int dx[4] = {+1,-1,+0,+0};
const int dy[4] = {+0,+0,-1,+1};

bool insideGrid(int &x,int &y,int &A,int &B){
    // return true if given point is inside the grid.
    return x >= 0 && x < A && y >= 0 && y < B;
}

int Solution::solve(int A, int B, vector<string> &C) {

    // boolean vector to keep track of visited nodes in bfs
    vector<vector<bool>>visited(A,vector<bool>(B,false));

    deque<node>q;

    //push source in queue
    q.push_front({0,0,0});
    visited[0][0] = 1;

    while( ! q.empty() ){
        node u = q.front();
        q.pop_front();

        // Reached destination, so return path length
        if( u.x == A-1 && u.y == B-1 ){
            return u.d;
        }

        // explore all the neighbours.
        for(int i=0;i<4;++i){
            int x = u.x + dx[i];
            int y = u.y + dy[i];
            int w = 1;

            if( ! insideGrid(x,y,A,B) || visited[x][y] ){
                continue;
            }

            // same direction so cost is zero
            if( C[x][y] == direction[i] ){
                w = 0;
            }

            int d = w + u.d;


            // here magic happnes
            // it is 0-1 weigted graph
            // so we can get shorted path using
            // bfs with the help of deque
            if( w ){
                q.push_back({x,y,d});
            }else{
                q.push_front({x,y,d});
            }

        }
    }

    // we can not reach to destination
    return NOT_REACHABLE;
}

/*
complexcity :-
    Space : O(n*m) for boolean visited vector
    Time  : O(n*m) we are using bfs, so every node once.
*/

