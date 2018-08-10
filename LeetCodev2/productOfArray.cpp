class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left(nums.size(), 0);
        vector<int> right(nums.size(), 0);
        vector<int> answer(nums.size(), 0);
        
        left[0] = nums[0];
        right[right.size() - 1] = nums[nums.size() - 1];
        
        for (int i = 1; i < nums.size(); i++) {
            left[i] = nums[i] * left[i - 1];
        }
        
        for (int i = nums.size() - 2; i >= 0; i--) {
            right[i] = nums[i] * right[i + 1];
        }
        
        for (int i = 0; i < nums.size(); i++) {
            int l = (0 == i) ? 1 : left[i - 1];
            int r = (nums.size() - 1 == i) ? 1 : right[i + 1];
            
            answer[i] = l * r;
        }
        
        return answer;
    }
};