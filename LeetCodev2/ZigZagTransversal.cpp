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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> current, next;
        vector<vector<int>> answer;
        vector<int> row;
        int level = 0;
        
        if (!root) return answer;
        
        current.push(root);
        
        while(!current.empty()) {
            
            TreeNode* c = current.front();
            current.pop();
            row.push_back(c->val);
            
            if (c->left) {
                next.push(c->left);
            }
            
            if (c->right) {
                next.push(c->right);
            }
            
            if (current.empty()) {
                if (level % 2 != 0) {
                    reverse(row.begin(), row.end());
                }
                answer.push_back(row);
                swap(current, next);
                row.clear();
                level++;
            }            
        }
        
        return answer;
    }
};