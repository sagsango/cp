class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        typedef long long ll;
        priority_queue< ll > maxHeap;
        priority_queue< ll, vector<ll>, greater<ll> > minHeap;
        ll n = nums.size(), m = n / 3, maxHeapSum = 0, minHeapSum = 0, min_diff = LONG_MAX;
        vector<ll>ldp(n,-1),rdp(n,-1);
        for(int i=0;i<n;++i){
            maxHeap.push(nums[i]);
            maxHeapSum += nums[i];
            if( maxHeap.size() > m ){
                maxHeapSum -= maxHeap.top();
                maxHeap.pop();
            }
            if( maxHeap.size() == m ){
                ldp[i] = maxHeapSum;
            }
        }
        for(int i=n-1;i>=0;--i){
            minHeap.push(nums[i]);
            minHeapSum += nums[i];
            if( minHeap.size() > m ){
                minHeapSum -= minHeap.top();
                minHeap.pop();
            }
            if( minHeap.size() == m ){
                rdp[i] = minHeapSum;
            }
        }
        for(int i=0;i+1<n;++i){
            if( ldp[i] != -1 && rdp[i+1] != -1 ){
                min_diff = min( min_diff, ldp[i] - rdp[i+1]);
            }
        }
        return min_diff;
        
    }
};
