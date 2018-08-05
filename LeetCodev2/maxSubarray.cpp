class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentMax = nums[0];
        int sum = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            int current = nums[i];
            
            sum = max(nums[i], sum + nums[i]);
            currentMax = max(sum, currentMax);
        }
        
        return currentMax;
    }
};