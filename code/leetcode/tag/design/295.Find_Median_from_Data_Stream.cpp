// https://leetcode.com/problems/find-median-from-data-stream/
class MedianFinder {
    priority_queue< int > MaxHeap;
    priority_queue< int, vector<int>, greater<int> > MinHeap;
    int tot_count, min_heap_count, max_heap_count;
public:
    MedianFinder() {
        tot_count = min_heap_count = max_heap_count = 0;
        
    }
    
    void addNum(int num) {
        // MaxHeap - MinHeap
        
        
        ++tot_count;
        if( max_heap_count <= min_heap_count ){
            ++max_heap_count;
        }else{
            ++min_heap_count;
        }
        
        if( MaxHeap.empty() || num <= MaxHeap.top() ){
            MaxHeap.push( num );
        }else{
            MinHeap.push( num );
        }
        
        while( MaxHeap.size() < max_heap_count ){
            MaxHeap.push( MinHeap.top() );
            MinHeap.pop();
        }
        
        while( MinHeap.size() < min_heap_count ){
            MinHeap.push( MaxHeap.top() );
            MaxHeap.pop();
        }
        
    }
    
    double findMedian() {
        if( tot_count & 1 )
            return MaxHeap.top();
        else
            return (1.00 * MaxHeap.top() + 1.00 * MinHeap.top() )/2;
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
