/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        
        if (!root) return;
        
        queue<TreeLinkNode*> currentL, nextL;
        TreeLinkNode* prev = NULL;
        currentL.push(root);
        
        while (!currentL.empty()) {
            TreeLinkNode* current = currentL.front();
            currentL.pop();
            
            if (prev) {
                prev->next = current;
            }
            
            prev = current;
            
            if (current->left) {
                nextL.push(current->left);
            }
            
            if (current->right) {
                nextL.push(current->right);
            }
            
            if (currentL.empty()) {
                current->next = NULL;
                swap(currentL, nextL);
                prev = NULL;
            }
        }      
    }
};