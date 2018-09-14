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
    void helper(TreeNode* root, int& first, int& second) {
        if (!root) return;
        
        int current = root->val;
        
        if (current < first) {
            second = first;
            first = current;
        } else if (current < second && current != first) {
            second = current;
        }
        
        helper(root->left, first, second);
        helper(root->right, first, second);
    }
    
    int findSecondMinimumValue(TreeNode* root) {
        int first = INT_MAX - 1;
        int second = INT_MAX;
        helper(root, first, second);
        return second != INT_MAX - 1 ? second : -1;
    }
};