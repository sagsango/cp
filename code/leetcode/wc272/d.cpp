const int nax = 1e5+10;
int bit[nax], m, z;
void update(int i,int val){
    while( i <= m ){
        bit[i] = max(bit[i],val);
        i += i & -i;
    }
}
int query(int i,int val=0){
    while( i > 0 ){
        val = max(val,bit[i]);
        i -= i & -i;
    }
    return val;
}
class Solution {
public:
    int kIncreasing(vector<int>& arr, int k) {
        int n = arr.size(), sum = 0;
        for(int i=0;i<k;++i){
            vector<int>order;
            for(int j=i;j<n;j+=k){
                order.push_back(arr[j]);
            }
            z = order.size();
            sort(order.begin(),order.end());
            order.erase(unique(order.begin(),order.end()),order.end());
            m = order.size();
            for(int i=1;i<=m;++i){
                bit[i] = 0;
            }
            int mx = 0;
            for(int j=i;j<n;j+=k){
                int val = lower_bound(order.begin(),order.end(),arr[j]) - order.begin() + 1;
                int ans = query(val)+1;
                update(val,ans);
                mx = max(mx,ans);
            }
            sum += z - mx;
        }
        return sum;
    }
};
