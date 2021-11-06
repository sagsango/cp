// https://leetcode.com/problems/binary-search-tree-iterator/
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

class BSTIterator {
    stack<TreeNode*>m_stack;
public:
    void add(TreeNode*root){
        while( root ){
            m_stack.push(root);
            root = root->left;
        }
    }
    BSTIterator(TreeNode* root) {
        add(root);
    }

    int next() {
        TreeNode* node = m_stack.top();
        m_stack.pop();
        add(node->right);
        return node->val;
    }

    bool hasNext() {
        return m_stack.size();

    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
