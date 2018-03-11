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
    bool helper(TreeNode* root, long int min, long int max) {
        if(!root) return true;
        
        int current = root->val;
        
        if (current <= min || current >= max) {
            return false;
        }
        
        return helper(root->left, min, current) && helper(root->right, current, max);
    } 
    
    bool isValidBST(TreeNode* root) {
        return helper(root, LLONG_MIN, LLONG_MAX);
    }
};