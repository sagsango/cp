class Solution {
    vector<int>par;
    int root(int u){ return par[u] < 0 ? u : par[u] = root(par[u]); }
    void merge(int u,int v){
        if( (u=root(u)) == (v=root(v)) ) return;
        if( par[u] > par[v] ) swap(u,v);
        par[u] += par[v];
        par[v] = u;
    }
public:
    bool gcdSort(vector<int>& nums){
        int mx = 0;
        for(auto x:nums){
            mx = max(mx, x);
        }
        par = vector<int>(mx+1,-1);
        vector<int>alive(mx+1,0);
        for(auto x:nums){
            alive[x] = 1;
        }
        for(int i=2;i<=mx;++i){
            int prv = alive[i] ? i : 0;
            for(int j=i;j<=mx;j+=i){
                if( alive[j] ){
                    if( prv )
                        merge(prv,j);
                    prv = j;
                    //cout << "merge" << i <<" "<< j << endl;
                }
            }
        }
        vector<int> tmp = nums;
        sort(tmp.begin(),tmp.end());
        for(int i=0;i<tmp.size();++i){
            if( /*tmp[i] != nums[i] && */ root(tmp[i]) != root(nums[i]) ){ // for nums[i] = 1 , the condition was written
                return 0;
            }
        }
        
        return 1;
       // 9, 9, 3, 10, 2
       // 2, 3, 9, 9, 10
        
    }
};
