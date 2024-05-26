class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        long long cost = 0;
        int x1 = startPos[0], y1 = startPos[1];
        int x2 = homePos[0], y2 = homePos[1];
        for(int i=x1;i != x2; ){
            i += (x1 < x2 ? +1 : -1);
            cost += rowCosts[i];
        }
        for(int j=y1;j != y2; ){
            j += (y1 < y2 ? +1 : -1);
            cost += colCosts[j];
        }
        return cost;
    }
};
