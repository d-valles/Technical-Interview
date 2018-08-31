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
    void helper(TreeNode* root, int &result) {
        if (!root) return;
        helper(root->left, result);
        
        if (checkUniValue(root->left, root->val) && checkUniValue(root->right, root->val)) result++;
        
        helper(root->right, result);
    }
    
    bool checkUniValue(TreeNode* root, int value) {
        if (!root) return true;
        if (root->val != value) return false;
        return checkUniValue(root->left, value) && checkUniValue(root->right, value);
    }
    
    int countUnivalSubtrees(TreeNode* root) {
        int result = 0;
        helper(root, result);
        return result;
    }
};