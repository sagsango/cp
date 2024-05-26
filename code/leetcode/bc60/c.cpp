class LockingTree {
    vector<int>lock_id, lock_sub, unlock_sub, parent;
    vector<vector<int>>g;
    int n;
public:
    void dfs_and_count(int u){
        ( lock_id[u] == -1  ? unlock_sub[u] : lock_sub[u] ) += 1;
        for(auto v:g[u]){
            dfs_and_count(v);
            lock_sub[u] += lock_sub[v];
            unlock_sub[u] += unlock_sub[v];
        }
    }
    void dfs_and_update(int u){
        lock_id[u] =  -1, lock_sub[u] = 0;
        unlock_sub[u] = 1;
        for(auto v:g[u]){
            if( lock_sub[v] ){
                dfs_and_update(v);
            }
            lock_sub[u] += lock_sub[v];
            unlock_sub[u] += unlock_sub[v];
        }
    }
    void update_parent(int u, int v1, int v2){
        if( u == - 1 ) return;
        lock_sub[u] += v1;
        unlock_sub[u] += v2;
        update_parent(parent[u], v1, v2);
    }
    void count_parent(int u,int &v1, int &v2){
        if( u == -1 ) return;
        v1 += lock_id[u] != -1;
        v2 += lock_id[u] == -1;
        count_parent(parent[u],v1,v2);
    }
    LockingTree(vector<int>& parent){
        this->parent = parent;
        n = parent.size();
        g = vector<vector<int>>(n);
        lock_id = lock_sub = unlock_sub = vector<int>(n);
        for(int i=0;i<n;++i){
            if( parent[i] >= 0 ){
                g[parent[i]].push_back(i);
            }
            lock_id[i] = -1;
        }
        dfs_and_count(0);
    }
    
    bool lock(int u, int user) {
        if( lock_id[u] == -1 ){
            lock_id[u] = user;
            update_parent(u,+1,-1);
            return 1;
        }
        return 0;
        
    }
    bool unlock(int u, int user) {
        if( lock_id[u] == user ){
            lock_id[u] = -1;
            update_parent(u,-1,+1);
            return 1;
        }
        return 0;
    }
    bool upgrade(int u, int user) {
        if( lock_id[u] == - 1 && lock_sub[u] != 0 ){
            int v1 = 0, v2 = 0;
            count_parent(parent[u],v1,v2);
            if( v1 == 0 ){
                dfs_and_update(u);
                lock_id[u] = user;
                lock_sub[u] += 1;
                unlock_sub[u] -= 1;
                return 1;
            }
        }
        return 0;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */
