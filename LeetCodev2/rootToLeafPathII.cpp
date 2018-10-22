/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 void dfs(TreeNode* current, int t, vector<int>& solution, vector<vector<int>>& a) {
     if (!current) {
         return;
     }
     
     solution.push_back(current->val);
     t -= current->val;
     
     if (t == 0 && !current->left && !current->right) {
         a.push_back(solution);
         solution.pop_back();
         return;
     }
     
    dfs(current->left, t, solution, a);
    dfs(current->right, t, solution, a);
    solution.pop_back();
 }
 
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    vector<vector<int>> a;
    vector<int> solution;
    
    if (!A) return a;
    
    dfs(A, B, solution, a);
    
    return a;
}
