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
    int kthSmallest(TreeNode* root, int k) {
        int numOfNode = 1;
        
        stack<TreeNode*> S;
        S.push(root);
        
        while(!S.empty() || root) {
            
            while(root) {
                S.push(root);
                root=root->left;
            }
            
            root = S.top();
            S.pop();
            
            if(k == numOfNode) {
                return root->val;
            }
            
            numOfNode++;
            
            root = root->right;
        }
        
    }
};