class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int water = 0, n = plants.size(), steps = 0;
        for(int i=-1;i+1<n;++i){
            if( water < plants[i+1] ){
                steps += 2 * ( i + 1 );
                water = capacity;
            }
            steps += 1;
            water -= plants[i+1];
        }
        return steps;
        
    }
};
