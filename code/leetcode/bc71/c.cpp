class Solution {
    int cost(int startAt, int moveCost, int pushCost, int minutes, int seconds){
        int cst = 0;
        vector<int>arr;
        for(int i=0;i<2;++i){
            arr.push_back(seconds%10);
            seconds /= 10;
        }
        for(int i=0;i<2;++i){
            arr.push_back(minutes%10);
            minutes /= 10;
        }
        reverse(arr.begin(),arr.end());
        int i = 0;
        while( i < 4 && arr[i] == 0 )
            ++i;
        while( i < 4 ){
            if( startAt != arr[i] ){
                cst += moveCost;
                startAt = arr[i];
            }
            cst += pushCost;
            ++i;
        }
        return cst;
    }
public:
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds){
        int min_cost = INT_MAX;
        for(int minutes = 0; minutes < 100; ++minutes){
            for(int seconds = 0; seconds < 100; ++seconds){
                int total_seconds = minutes * 60 + seconds;
                if( total_seconds == targetSeconds ){
                    min_cost = min( min_cost, cost(startAt,moveCost,pushCost,minutes,seconds));
                }
            }
        }
        return min_cost;
        
    }
};
