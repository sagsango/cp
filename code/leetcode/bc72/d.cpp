
#define B 320
struct box{
    int l, r, i;
    bool operator<(const box& b){
        if( l / B  != b.l / B ){
            return  l / B < b.l / B;
        }
        return r / B < b.r / B;
    }
};


const int nax = 1e5;
static int sum = 0, cnt[nax];

inline void add(int &idx){
            assert(idx >= 0 );
            if( cnt[idx] == 1 ){
                ++sum;
            }
            ++cnt[idx];
};

inline void remove(int &idx){
            assert( idx >= 0 );
            if( cnt[idx] == 2 ){
                --sum;
            }
            --cnt[idx];
};

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2){
             
        int n = nums1.size();
        vector<int>mp1(n),mp2(n);
        for(int i=0;i<n;++i){
            mp1[nums1[i]] = i;
            mp2[nums2[i]] = i;
        }
        
        vector<box>L(n),R(n);
        for(int i=0;i<n;++i){
            L[i] = {mp1[i]-1,mp2[i]-1,i};
            R[i] = {mp1[i]+1,mp2[i]+1,i};
        }
        sort(L.begin(),L.end());
        sort(R.begin(),R.end());
        
        vector<long long>ans(n,1LL);
        
        
        memset(cnt,0,sizeof(cnt));
        sum = 0;
        int l = 0, r = 0;
        for(int i=0;i<n;++i){
            int _l = L[i].l;
            int _r = L[i].r;
            int _i = L[i].i;
            while( l <= _l ){
                add(nums1[l]);
                ++l;
            }
            while( r <= _r ){
                add(nums2[r]);
                ++r;
            }
            while( l > _l + 1 ){
                --l;
                remove(nums1[l]);
                
            }
            while( r > 1 + _r ){
                --r;
                remove(nums2[r]);
                
            }
            ans[_i] *= sum;
        }
        
        
        
        memset(cnt,0,sizeof(cnt));
        sum = 0;
        l = n-1, r = n-1;
        for(int i=0;i<n;++i){
            int _l = R[i].l;
            int _r = R[i].r;
            int _i = R[i].i;
            while( l >= _l ){
                add(nums1[l]);
                --l;
            }
            while( r >= _r ){
                add(nums2[r]);
                --r;
            }
            while( l < _l - 1 ){
                 ++l;
                remove(nums1[l]);
               
            }
            while( r < _r - 1 ){
                 ++r;
                remove(nums2[r]);
               
            }
            ans[_i] *= sum;
            
        }
        
        
        
        long long ret = 0;
        for(int i=0;i<n;++i){
            ret += ans[i];
        }
        
        return ret;
    }
};



//BIT solution 
// by hank55663 
class Solution {
public:
    int S[100005];
    int n;
    void add(int x,int k){
        x++;
        for(int i = x;i<=n;i+=i&-i)S[i]+=k;
    }
    int query(int x){
        int res=0;
        x++;
        for(int i =x;i>0;i-=i&-i)res+=S[i];
        return res;
    }
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        fill(S,S+nums1.size()+1,0);
        n=nums1.size();
        vector<pair<int,int> > v(nums1.size());
        for(int i = 0;i<nums1.size();i++){
            v[nums1[i]].first=i;
        }
        for(int i = 0;i<nums2.size();i++){
            v[nums2[i]].second=i;
        }
        sort(v.begin(),v.end());
        long long cnt[100005];
        long long cnt2[100005];
        for(int i = 0;i<nums1.size();i++){
            cnt[i]=query(v[i].second);
            add(v[i].second,1);
        }
        //for(int i = 0;i<nums1.size();i++)add(v[i].second,-1);
           fill(S,S+nums1.size()+1,0);
        int tot=0;
        long long res=0;
        for(int i = nums1.size()-1;i>=0;i--){
            cnt2[i]=tot-query(v[i].second);
            add(v[i].second,1);
            res+=cnt[i]*cnt2[i];
            tot++;
          //  printf("%d %d\n",cnt[i],cnt2[i]);
        }
        //for(int i = 0;i<nums1.size();i++)add(v[i].second,-1);
        return res;
    }
};

