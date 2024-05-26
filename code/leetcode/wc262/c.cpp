class StockPrice {
    unordered_map<int,int>hashMap;
    multiset<int>BSTwithDuplicates;
    int maxTimeStamp;
public:
    StockPrice() {
        maxTimeStamp = -1e9;
    }
    
    void update(int timestamp, int price) {
        if( hashMap.find(timestamp) != hashMap.end() ){
            BSTwithDuplicates.erase(BSTwithDuplicates.find(hashMap[timestamp]));
        }
        hashMap[timestamp] = price;
        BSTwithDuplicates.insert(hashMap[timestamp]);
        if( timestamp > maxTimeStamp ){
            maxTimeStamp = timestamp;
        }
    }
    
    
    int current() {
        return hashMap[maxTimeStamp];
        
    }
    
    
    int maximum() {
        return *(--BSTwithDuplicates.end());
        
    }
    
    
    int minimum() {
        return *(BSTwithDuplicates.begin());
        
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
