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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> answer;
        if (!root) return answer;
        
        vector<int> level;
        queue<TreeNode*> current;
        queue<TreeNode*> next;
        
        current.push(root);
        
        while(!current.empty()) {
            TreeNode* c = current.front();
            current.pop();
            
            level.push_back(c->val);
            
            if (c->left) {
                next.push(c->left);
            }
            
            if (c->right) {
                next.push(c->right);
            }
            
            if (current.empty()) {
                current = next;
                next = queue<TreeNode*>();
                answer.push_back(level);
                level.clear();
            }
        }
        
        return answer;
    }
};