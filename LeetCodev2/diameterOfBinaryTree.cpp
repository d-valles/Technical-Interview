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
    int height (TreeNode* root) {
        if (!root) return 0;
        
        return 1 + max(height(root->left), height(root->right));
    }
    
    void helper(TreeNode* root, int& diameter) {
        if (!root) return;
        
        int left = height(root->left);
        int right = height(root->right);
        
        int sum = (left + right);
        
        diameter = max(diameter, sum);
        
        helper(root->left, diameter);
        helper(root->right, diameter);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        helper(root, diameter);
        return diameter;
    }
};