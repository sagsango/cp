class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        
        auto cmp = [&](const int &i, const int &j){
            return plantTime[i] + max(growTime[i], plantTime[j] + growTime[j]) <
                plantTime[j] + max(growTime[j], plantTime[i] + growTime[i]);
        };
        
        int n = plantTime.size();
        vector<int>order(n);
        for(int i=0;i<n;++i){
            order[i] = i;
        }
        
        sort(order.begin(),order.end(),cmp);
        
        int total_plant_time = 0, min_bloom_time = 0;
        for(int i:order){
            min_bloom_time = max(min_bloom_time, total_plant_time + plantTime[i] + growTime[i] + 1);
            total_plant_time += plantTime[i];
        }
        return min_bloom_time - 1; 
    }
};
