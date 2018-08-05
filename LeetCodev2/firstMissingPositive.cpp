class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size();) {
            int current = nums[i] - 1;
            while (i != current && current < nums.size() && current >= 0 && current != nums[current] - 1) {
                swap(nums[i], nums[current]);
                current = nums[i] - 1;
            }
            i++;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (i + 1 != nums[i]) return i + 1;    
        }
        
        return nums.size() + 1;
    }
};