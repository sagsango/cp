// TODO: If cycle is present, it will be taken care by tpl.
class Solution {
    unordered_map<string,vector<string>> g, gr;
    unordered_set<string>vis, all, alive;
    vector<string>tpl;
    void dfs(string u){
        vis.insert(u);
        for(auto v:g[u]){
            if(!vis.count(v)){
                dfs(v);
            }
        }
        tpl.push_back(u);
    }
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        g.clear(), gr.clear(), vis.clear(), all.clear(), alive.clear(), tpl.clear();
        for(int i=0;i<recipes.size();++i){
            for(int j=0;j<ingredients[i].size();++j){
                g[ingredients[i][j]].push_back(recipes[i]);
                gr[recipes[i]].push_back(ingredients[i][j]);
                all.insert(ingredients[i][j]);
            }
            all.insert(recipes[i]);
        }
        for(auto node:supplies){
            all.insert(node);
            alive.insert(node);
        }
        for(auto node:all){
            if( !vis.count(node)){
                dfs(node);
            }
        }
        reverse(tpl.begin(),tpl.end());
        for(auto node:tpl){
            if( gr[node].empty() ){
                continue;
            }
            int ok = 1;
            for(auto need:gr[node]){
                if( !alive.count(need) ){
                    ok = 0;
                    break;
                }
            }
            if( ok ){
                alive.insert(node);
            }
        }
        vector<string>ans;
        for(auto node:recipes){
            if( alive.count(node) ){
                ans.push_back(node);
            }
        }
        return ans;
        
        
    }
};
