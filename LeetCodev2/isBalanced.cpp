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
    int helperMax(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(helperMax(root->left), helperMax(root->right));
    }
    
    
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        
        int leftH = helperMax(root->left);
        int rightH = helperMax(root->right);
        
        if (abs(leftH - rightH) <= 1 && isBalanced(root->left) && isBalanced(root->right)) {
            return true;
        }
        
        return false;
    }
};