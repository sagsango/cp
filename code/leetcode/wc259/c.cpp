class DetectSquares {
    map<int,int>hashMap;
public:
    DetectSquares() {
        hashMap.clear();
        
    }
    
    void add(vector<int> point) {
        hashMap[point[0] * 1001 + point[1] ] += 1;
        
    }
    
    int count(vector<int> point) {
        int cnt, x1 = point[0], y1 = point[1];
        cnt = 0;
        for(map<int,int>::iterator it = hashMap.begin(); it != hashMap.end(); ++it){
            int x3 = it->first / 1001;
            int y3 = it->first % 1001;
            if( x3 != x1 && y3 != y1 && abs(x1-x3) == abs(y1-y3) ){
                int x2 = x1, y2 = y3;
                int x4 = x3, y4 = y1;
                cnt += hashMap[x2 * 1001 + y2 ] * hashMap[x3 * 1001 + y3 ] * hashMap[ x4 * 1001 + y4];
            }
        }
        return cnt;
        
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
