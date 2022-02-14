class Solution {
public:
    long long minimumRemoval(vector<int>& beans){
        typedef long long ll;
        ll cur_beans = 0, smaller_sum = 0, smaller_cnt = 0, bigger_sum = 0, bigger_cnt = 0, cost = LONG_MAX;
        
        
        priority_queue< int, vector<int>, greater<int> > MinHeap;
        for(auto x:beans){
            bigger_sum += x;
            bigger_cnt += 1;
            MinHeap.push(x);
        }
        
        while( cur_beans <= 1e5 ){
            while( MinHeap.size() && MinHeap.top() < cur_beans ){
                int x = MinHeap.top();
                MinHeap.pop();
                bigger_sum -= x;
                bigger_cnt -= 1;
                smaller_sum += x;
                smaller_cnt += 1;
            }
            cost = min(cost, smaller_sum + bigger_sum - bigger_cnt * cur_beans);
            ++cur_beans;
        }
        return cost;
        
        
    }
};
