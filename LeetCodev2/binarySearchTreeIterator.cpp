/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        inorder(root);
    }
    
    void inorder(TreeNode *root) {
        if (!root) return;
        
        inorder(root->left);
        inorderQ.push(root);
        inorder(root->right);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return inorderQ.size() >= 1;
    }

    /** @return the next smallest number */
    int next() {
        int n = inorderQ.front()->val;
        inorderQ.pop();
        return n;
    }
private:
    queue<TreeNode*> inorderQ;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */