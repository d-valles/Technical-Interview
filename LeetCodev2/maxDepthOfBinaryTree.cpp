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
    int recursiveDepth(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(recursiveDepth(root->left), recursiveDepth(root->right));
    }
    
    int iterativeDepth(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> Q;
        Q.push(root);

        int level = 0;
        int toPop = 1;

        while (!Q.empty()) {
            TreeNode* current = Q.front();
            toPop--;
            Q.pop();

            if (current->left) {
                Q.push(current->left);
            }

            if (current->right) {
                Q.push(current->right);
            }

            if (toPop == 0) {
                level++;
                toPop = Q.size();
            }
        }

        return level;
    }
    
    int maxDepth(TreeNode* root) {
        return recursiveDepth(root);
    }
};