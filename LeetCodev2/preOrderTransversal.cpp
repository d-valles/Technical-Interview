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
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};
        
        vector<int> answer;
        stack<TreeNode*> S;
        S.push(root);
        
        while (!S.empty()) {
            TreeNode* c = S.top();
            S.pop();
            
            answer.push_back(c->val);
            
            if (c->right) {
                S.push(c->right);
            }
            
            if (c->left) {
                S.push(c->left);   
            }
            
        }
        
        return answer;
    }
};