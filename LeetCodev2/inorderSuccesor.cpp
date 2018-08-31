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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!root || !p) return (TreeNode*)NULL;
        
        stack<TreeNode*> S;
        TreeNode* current = root;
        bool found = false;
        
        while(!S.empty() || current) {
            while(current) {
                S.push(current);
                current = current->left;
            }
            
            current = S.top();
            S.pop();
            
            if (found) return current;
            
            if (current->val == p->val) {
                found = true;
            }
            
            current = current->right;      
        }
        
        return (TreeNode*)NULL;
    }
};