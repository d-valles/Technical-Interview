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
    int helper(TreeNode* current, int sum) {
        if (!current) {
            return 0;
        }
        
        sum = (10 * sum) + current->val;
        
        if (!current->left && !current->right) {
            return sum;
        }
        
        if (!current->left) {
            return helper(current->right, sum);
        }
        
        if (!current->right) {
            return helper(current->left, sum);
        }
        
        if (current->left && current->right) {
            return helper(current->left, sum) + helper(current->right, sum);
        }
    }
    
    int sumNumbers(TreeNode* root) {
        return helper(root, 0);
    }
};