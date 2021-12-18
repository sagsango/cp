class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength){
        int n = tasks.size(), m = workers.size();
        int l = 0, r = min(n,m), ans = 0;
        sort(workers.begin(),workers.end());
        sort(tasks.begin(),tasks.end());
        while( l <= r ){
            int mid = ( l + r ) >> 1;
            long long cnt = 0, ok = 1;
            multiset<int>ms;
            for(int i=0;i<mid;++i){
                ms.insert(tasks[i]);
            }
            for(int i=0;i<mid;++i){
                int x = workers[m-mid+i];
                auto it = ms.begin();
                if( *it  <= x ){
                    ms.erase(it);
                }else{
                    ++cnt;
                    x += strength;
                    it = ms.lower_bound(x);
                    if( it == ms.end() || *it > x ){
                        if( it == ms.begin() ){
                            ok = 0;
                            break;
                        }
                        --it;
                    }
                    ms.erase(it);
                }
            }
            if( cnt <= pills && ok ){
                ans = max(ans,mid);
                l = mid+1;
            }else
                r = mid-1;
        }
        return ans;
    }
};
