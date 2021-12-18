/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode * lca;
    int hs, hlca;
    string path, cur_path;
    int dfsLCA(TreeNode *root, int h, int start, int dest){
        int terminal_count = 0;
        if( root ){
            terminal_count = ( root->val == start ) + 
                                (root->val == dest) + 
                                dfsLCA(root->left,h+1,start,dest) + 
                                dfsLCA(root->right,h+1,start,dest);
            if( terminal_count == 2 && lca == NULL ){
                hlca = h;
                lca = root;
            }
            if( root->val == start ){
                hs = h;
            }
        }
        return terminal_count;
    }
    void dfsPath(TreeNode * root,int dest){
        if( root ){
            
            if( root->val == dest){
                path += cur_path;
            }
            
            cur_path.push_back('L');
            dfsPath(root->left,dest);
            cur_path.pop_back();
            
            cur_path.push_back('R');
            dfsPath(root->right,dest);
            cur_path.pop_back();
        }
    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        lca = NULL;
        dfsLCA(root,0,startValue,destValue);
        path = "";
        while( hs != hlca ){
            path.push_back('U');
            --hs;
        }
        cur_path = "";
        dfsPath(lca,destValue);
        return path;
    }
};
