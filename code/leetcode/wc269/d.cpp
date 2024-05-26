class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meet, int firstPerson) {
        auto cmp = [&](vector<int>&a,vector<int>&b){
            return a[2] < b[2];
        };
        sort(meet.begin(),meet.end(),cmp);
        vector<int>alive(n), vis(n), g[n];
        alive[0] = alive[firstPerson] = 1;
        int i = 0, m = meet.size();
        while( i < m ){
            int time = meet[i][2], j = i;
            vector<int>person;
            while( j < m && meet[j][2] == time ){
                person.push_back(meet[j][0]);
                person.push_back(meet[j][1]);
                ++j;
            }
            sort(person.begin(),person.end());
            person.erase(unique(person.begin(),person.end()),person.end());
            for(auto p:person){
                g[p].clear();
            }
            j = i;
            while( j < m && meet[j][2] == time ){
                g[meet[j][1]].push_back(meet[j][0]);
                g[meet[j][0]].push_back(meet[j][1]);
                ++j;
            }
            for(auto p:person){
                if( vis[p] != time ){
                    vector<int>cmp;
                    queue<int>q;
                    int ok = 0;
                    q.push(p);
                    vis[p] = time;
                    while( q.size() ){
                        int u = q.front();
                        cmp.push_back(u);
                        ok |= alive[u];
                        q.pop();
                        for(auto v:g[u]){
                            if( vis[v] != time ){
                                vis[v] = time;
                                q.push(v);
                            }
                        }
                    }
                    if( ok ){
                        for(auto p:cmp){
                            alive[p] = 1;
                        }
                    }
                }
            }
            i = j;
        }
        vector<int>ans;
        for(int p=0;p<n;++p){
            if( alive[p] ){
                ans.push_back(p);
            }
        }
        return ans;
    }
};
