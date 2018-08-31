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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> answer;
        if (!root) return answer;
        
        stack<TreeNode*> S;
        S.push(root);
        
        while(!S.empty()) {
            TreeNode* current = S.top();
            while(current->left) {
                S.push(current->left);
                current->left = NULL;
                current = S.top();
            }
            
            answer.push_back(current->val);
            S.pop();
            
            if (current->right) {
                S.push(current->right);
            }            
        }
        
        return answer;
    }
};

/*
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> answer;
        if (!root) return answer;
        
        stack<TreeNode*> S;
        TreeNode* current = root;
        
        while(!S.empty() || current) {
            while(current) {
                S.push(current);
                current = current->left;
            }
            
            current = S.top();
            S.pop();
            answer.push_back(current->val);
            
            current = current->right;      
        }
        
        return answer;
    }
};
*/