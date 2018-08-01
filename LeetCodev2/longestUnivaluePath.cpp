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
    int heightWithSameValue(TreeNode* current, int target) {
        if (!current || current->val != target) return 0;
        return 1 + max(heightWithSameValue(current->left, target), heightWithSameValue(current->right, target));
    }
    
    void helper(TreeNode* current, int& value) {
        if (!current) return;
        
        int left = heightWithSameValue(current->left, current->val);
        int right = heightWithSameValue(current->right, current->val);
        value = max(value, left + right);
        
        helper(current->left, value);
        helper(current->right, value);
    }
    
    int longestUnivaluePath(TreeNode* root) {
        int answer = 0;
        helper(root, answer);
        return answer;
    }
};