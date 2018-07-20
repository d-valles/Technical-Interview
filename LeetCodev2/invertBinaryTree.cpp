/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void helper(TreeNode* root) {
        if (!root) return;
        
        TreeNode* newLeft = root->right;
        TreeNode* newRight = root->left;
        
        root->left = newLeft;
        root->right = newRight;
        
        helper(root->left);
        helper(root->right);       
    }
    
    TreeNode* invertTree(TreeNode* root) {
        helper(root);
        return root;
    }
};