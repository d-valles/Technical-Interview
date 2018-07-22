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
    bool createPath(TreeNode* current, TreeNode* target, vector<TreeNode*>& path) {
        if (!current) {
            return false;  
        }
        
        path.push_back(current);
        
        if (current == target) {
            return true;
        }
        
       if (createPath(current->left, target, path) || createPath(current->right, target, path)){
           return true;
       }
        
       path.pop_back();
       return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ancestor = NULL;
        vector<TreeNode*> pathP, pathQ;
        
        if (!createPath(root, p, pathP) || !createPath(root, q, pathQ)) {
            return NULL;
        }
        
        int i = 0;
        for (; i < pathP.size() && i < pathQ.size(); i++) {
            if (pathP[i] != pathQ[i]) {
                break;
            }
        }
        
        return pathP[i - 1];
    }
};