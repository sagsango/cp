/*
Simple implimentation - do dfs/bfs in coprime number component and update evey member in component to their component size
*/

class Solution {
    vector<set<int>> g;
    vector<int>nonprime, dp, vis, par;
    
    int root(int u){
        return par[u] < 0 ? u : par[u] = root(par[u]);
    }
    void merge(int u, int v){
        if((u=root(u)) == (v=root(v))){
            return;
        }
        if(par[u] > par[v])
            swap(u,v);
        par[u] += par[v];
        par[v] = u;
    }
    
    
    void dfs(int u, int p){
        cout << u << endl;
        vis[u] += 1;
        dp[u] = 1;
        for(auto v:g[u]){
            if( v != p && nonprime[v]){
                dfs(v,u);
                dp[u] += dp[v];
            }
        }
    }
public:
    long long countPaths(int n, vector<vector<int>>& edges) {
        
        long long ans = 0;
        g =  vector<set<int>>(n+1);
        nonprime = dp = vis = vector<int>(n+1);
        par = vector<int>(n+1,-1);
        
        
        nonprime[0] = nonprime[1] = 1;
        for(int i=2;i<=n;++i){
            if(!nonprime[i]){
                for(long long j=1ll*i*i;j<=n;j+=i){
                    nonprime[j] = 1;
                }
            }
        }
        
        
        
        for(auto &v:edges){
            int x = v[0], y = v[1];
            
            if(nonprime[x] && nonprime[y]){
                merge(x,y);
            }
        }
        
        
        for(auto &v:edges){
            int x = root(v[0]), y = root(v[1]);
            if( x == y )
                continue;
            g[x].insert(y);
            g[y].insert(x);
        }
        
        
        //cout << "n:" << n << endl;
        for(int i=1; i<=n; ++i){
            //cout << "par[" << i << "]" << ":" << root(i) << endl;
            
            if(!nonprime[i]){
                //cout << "------" << i << "------" << endl;
                //dfs(i,0);
                
                long long sum = 0, tmp = 0, node_sum = 0;
                for(auto v:g[i]){
                    if(nonprime[v]){
                        sum += -par[v];
                        //cout << "[u,v,-par[v]]:" << i << " " << v << " " << -par[v] << endl;
                    }
                }
                
                node_sum += sum * 1;
                
                for(auto v:g[i]){
                    if(nonprime[v])
                        tmp += -par[v] * (sum + par[v]);
                   
                }
                
                node_sum += tmp/2;
                //cout << i <<" " << node_sum <<" "<< tmp << " "<< sum << endl;
                ans += node_sum;
            }
        }
        /*for(int i=1;i<=n;++i){
            //assert(vis[i] < 3);
        }*/
        return ans;
    }
};
