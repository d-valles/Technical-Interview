/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    queue<TreeNode*> current;
    queue<TreeNode*> next;
    vector<vector<int>> answer;
    vector<int> level;
    
    current.push(A);
    
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
            answer.push_back(level);
            level.clear();
            current = next;
            next = queue<TreeNode*>();
        }
    }
    
    return answer;
}
