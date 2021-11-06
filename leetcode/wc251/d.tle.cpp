class tree{
    public:
        map<string,tree*>child;
        int size;
        bool alive;
        tree(){
            size = 0, child.clear(), alive = 1;
        }
        static void insert(tree*root,vector<string>&path);
        static bool cmp(tree*,tree*);
        static void dfs(tree*);
};
tree * root;
map<pair<tree*,tree*>,bool>dp;
set<pair<tree*,tree*>>vis;
vector<tree*>nodes;
vector<vector<string>>ans;
vector<string>cur_path;
void tree::insert(tree*root,vector<string>&path){
        tree * cur = root;
        for(auto dir:path){
            if( cur->child[dir] == nullptr ){
                cur->child[dir] = new tree();
                nodes.push_back(cur->child[dir]);
            }
            cur = cur->child[dir];
            cur->size += 1;
        }
}
bool tree::cmp(tree*a,tree*b){
        //if( vis.find({a,b}) != vis.end()  )
            //return dp[{a,b}];
        //vis.insert({a,b});
        bool  ans = 0; //dp[{a,b}];
        if( a == nullptr && b == nullptr )
            return ans = true;
        if( a == nullptr || b == nullptr )
            return ans = false;
        if( a->size != b->size )
            return ans = false;
        for(auto i = a->child.begin(), j = b->child.begin(); i != a->child.end() && j != b->child.end(); ++i, ++j){
            if( i->first != j->first ){
                return ans = false;
            }
        }
        for(auto i = a->child.begin(), j = b->child.begin(); i != a->child.end() && j != b->child.end(); ++i, ++j){
            if( tree::cmp(i->second,j->second) == false){
                return ans = false;
            }
        }
        return ans = true;
}
void tree::dfs(tree*root){
    if( cur_path.size() ){
        ans.emplace_back(cur_path);
    }
    for(auto [dir,ptr]:root->child){
       
        if( ! ptr->alive )
            continue;
        cur_path.push_back(dir);
        dfs(ptr);
        cur_path.pop_back();
    }
}
class Solution {
public:
    Solution(){
        root = NULL;
        dp.clear();
        nodes.clear();
        ans.clear();
        cur_path.clear();
    }
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        root = new tree();
        for(auto path:paths){
            tree::insert(root,path);
        }
        for(auto a:nodes){
            for(auto b:nodes){
                if( a != b  && !a->child.empty() && !b->child.empty() ){
                    if( tree::cmp(a,b) ){
                        a->alive = b->alive = 0;
                    }
                }
            }
        }
        tree::dfs(root);
        return ans;
        
    }
};
