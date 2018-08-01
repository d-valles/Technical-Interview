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
    void helper (TreeNode* root, double target, int& answer) {
        if(!root) return;
        
        double diff = abs(root->val - target);
        
        if (answer == -1 || diff < abs(answer - target) ) {
            answer = root->val;
        }
        
        helper(root->left, target, answer);
        helper(root->right, target, answer);
    }
    
    int closestValue(TreeNode* root, double target) {
        if (!root) return 0;
        int answer = -1;
        
        helper(root, target, answer);
        return answer;
    }
};