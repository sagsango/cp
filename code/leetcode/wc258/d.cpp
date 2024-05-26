/*
#define BLOCK 505
struct box{
    int u,l,r;
    bool operator<(const box & other)const{
        if( l / BLOCK != other.l / BLOCK )
            return l / BLOCK < other.l / BLOCK;
        return r / BLOCK < other.r / BLOCK;
    }
};

const int nax = 1e5+5;
vector<int>g[nax];
int pos[nax],arr[nax],sub[nax],bit[nax], cnt[nax], n, m, cur_pos;
vector<box>tmp(nax);

void dfs(int u){
    pos[u] = cur_pos++;
    arr[pos[u]] = u;
    sub[u] = 1;
    for(auto v:g[u]){
        dfs(v);
        sub[u] += sub[v];
    }
}
void update(int i,int val){
    while( i <= m )
        bit[i] += val, i += i & -i;
}

int query(int i,int val=0){
    while( i > 0 )
        val += bit[i], i-= i & -i;
    return val;
}

int query(){
    if( query(1) == 0 )
        return 1;
    int l = 1, r = m+1;
    while( l + 1 < r ){
        int mid = (l+r)>>1;
        ( query(mid) >= mid ? l : r ) = mid;
    }
    return l+1;
}

void add(int i){
    if( cnt[i] == 0 ){
        update(i,+1);
    }
    ++cnt[i];
}
void remove(int i){
    if( cnt[i] == 1 ){
        update(i,-1);
    }
    --cnt[i];
}
class Solution {
public:
    
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums){
        n = parents.size(), m = cur_pos = 0;
        for(int i=0;i<n;++i){
            g[i].clear();
            m = max(m, nums[i]);
        }
        for(int i=0;i<=m;++i){
            bit[i] = cnt[i] = 0;
        }
        for(int i=1;i<n;++i){
            g[parents[i]].push_back(i);
        }
        dfs(0);
        for(int i=0;i<n;++i){
            tmp[i] = {i,pos[i],pos[i]+sub[i]-1};
        }
        
        sort(tmp.begin(),tmp.begin()+n);
        vector<int>ans(n);
        
        //return {};
        int l = 0, r = 0;
        for(int i=0;i<n;++i){
            while( r <= tmp[i].r ){
                add(nums[arr[r]]);
                ++r;
            }
            while( l > tmp[i].l ){
                --l;
                add(nums[arr[l]]);
            }
            while( r > tmp[i].r + 1 ){
                --r;
                remove(nums[arr[r]]);
            }
            while( l < tmp[i].l ){
                remove(nums[arr[l]]);
                ++l;
            }
            ans[tmp[i].u] = query();
        }
        return ans;
    }
};
*/



/*
#define BLOCK 505
struct box{
    int u,l,r;
    bool operator<(const box & other)const{
        if( l / BLOCK != other.l / BLOCK )
            return l / BLOCK < other.l / BLOCK;
        return r / BLOCK < other.r / BLOCK;
    }
};

const int nax = 1e5+5;
vector<int>g[nax];
int pos[nax],arr[nax],sub[nax], cnt[nax], n, m, cur_pos;
vector<box>tmp(nax);

set<int>dead;
void dfs(int u){
    pos[u] = cur_pos++;
    arr[pos[u]] = u;
    sub[u] = 1;
    for(auto v:g[u]){
        dfs(v);
        sub[u] += sub[v];
    }
}
void update(int i,int val){
    if( val == +1 ){
        dead.erase(i);
    }else{
        dead.insert(i);
    }
}

int query(){
    return *dead.begin();
}

void add(int i){
    if( cnt[i] == 0 ){
        update(i,+1);
    }
    ++cnt[i];
}
void remove(int i){
    if( cnt[i] == 1 ){
        update(i,-1);
    }
    --cnt[i];
}
class Solution {
public:
    
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums){
        dead.clear();
    
        n = parents.size(), m = cur_pos = 0;
        for(int i=0;i<n;++i){
            g[i].clear();
            m = max(m, nums[i]);
        }
        
        for(int i=1;i<=m+1;++i){
            dead.insert(i);
        }
        for(int i=0;i<=m;++i){
            cnt[i] = 0;
        }
        for(int i=1;i<n;++i){
            g[parents[i]].push_back(i);
        }
        dfs(0);
        for(int i=0;i<n;++i){
            tmp[i] = {i,pos[i],pos[i]+sub[i]-1};
        }
        
        sort(tmp.begin(),tmp.begin()+n);
        vector<int>ans(n);
        
        //return {};
        int l = 0, r = 0;
        for(int i=0;i<n;++i){
            while( r <= tmp[i].r ){
                add(nums[arr[r]]);
                ++r;
            }
            while( l > tmp[i].l ){
                --l;
                add(nums[arr[l]]);
            }
            while( r > tmp[i].r + 1 ){
                --r;
                remove(nums[arr[r]]);
            }
            while( l < tmp[i].l ){
                remove(nums[arr[l]]);
                ++l;
            }
            ans[tmp[i].u] = query();
        }
        return ans;
    }
};
*/

// TODO: Adding these lines converted TLE -> AC
#pragma GCC target("popcnt")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native"

#define BLOCK 505
struct box{
    int u,l,r;
    bool operator<(const box & other)const{
        if( l / BLOCK != other.l / BLOCK )
            return l / BLOCK < other.l / BLOCK;
        return r / BLOCK < other.r / BLOCK;
    }
};

const int nax = 1e5+5;
vector<int>g[nax];
int pos[nax],arr[nax],sub[nax], cnt[nax], n, m, cur_pos;
vector<box>tmp(nax);

bitset< nax > unused;


void dfs(int u){
    pos[u] = cur_pos++;
    arr[pos[u]] = u;
    sub[u] = 1;
    for(auto v:g[u]){
        dfs(v);
        sub[u] += sub[v];
    }
}
void update(int i,int val){
    if( val == +1 ){
        unused[i] = 0;
    }else{
        unused[i] = 1;
    }
}


int query(){
    return unused._Find_next(0);
}

void add(int i){
    if( cnt[i] == 0 ){
        update(i,+1);
    }
    ++cnt[i];
}
void remove(int i){
    if( cnt[i] == 1 ){
        update(i,-1);
    }
    --cnt[i];
}
class Solution {
public:
    
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums){
        n = parents.size(), m = cur_pos = 0;
        for(int i=0;i<n;++i){
            g[i].clear();
            m = max(m, nums[i]);
        }
        for(int i=0;i<=m;++i){
            cnt[i] = 0;
            unused[i] = 1;
        }
        unused[m+1] = 1;
        
        for(int i=1;i<n;++i){
            g[parents[i]].push_back(i);
        }
        dfs(0);
        for(int i=0;i<n;++i){
            tmp[i] = {i,pos[i],pos[i]+sub[i]-1};
        }
        
        sort(tmp.begin(),tmp.begin()+n);
        vector<int>ans(n);
        
        //return {};
        int l = 0, r = 0;
        for(int i=0;i<n;++i){
            while( r <= tmp[i].r ){
                add(nums[arr[r]]);
                ++r;
            }
            while( l > tmp[i].l ){
                --l;
                add(nums[arr[l]]);
            }
            while( r > tmp[i].r + 1 ){
                --r;
                remove(nums[arr[r]]);
            }
            while( l < tmp[i].l ){
                remove(nums[arr[l]]);
                ++l;
            }
            ans[tmp[i].u] = query();
        }
        return ans;
    }
};
