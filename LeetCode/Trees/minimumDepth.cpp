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
	int recursiveMinDepth(TreeNode *root) {
    	if(!root) return 0;

    	if(!root->left || !root->right){
    		return 1 + max(recursiveMinDepth(root->left), recursiveMinDepth(root->right));
    	}

    	return 1 + min(recursiveMinDepth(root->left), recursiveMinDepth(root->right));
    }

    int iterativeMinDepth(TreeNode* root) {
    	if(!root) return 0;

    	queue<TreeNode*> Q;
    	Q.push(root);
    	int depth = 0;
    	int children = 0;

    	while(!Q.empty()) {
    		children = Q.size();
    		depth++;
    		for(int i = 0; i < children; i++) {
    			current = Q.front();
    			Q.pop();
    	
	    		if(!current->left && !current->right) return depth;
	    		if(current->left){
	    			Q.push(current->left);
	    		}
	    		if(current->right) {
	    			Q.push(current->right);
	    		}
    		}
    	}

    	return depth;
    }
    int minDepth(TreeNode* root) {
    	//recursiveMinDepth(root);
    	return iterativeMinDepth(root);
    }
};