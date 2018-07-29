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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (!nums.size()) return NULL;

        int mid = nums.size() / 2;
        
        TreeNode* newNode = new TreeNode(nums[mid]);
        
        vector<int> left(nums.begin(), nums.begin() + mid);
        vector<int> right(nums.begin() + mid + 1, nums.end());
        
        newNode->left = sortedArrayToBST(left);
        newNode->right = sortedArrayToBST(right);
        
        return newNode;
    }
};