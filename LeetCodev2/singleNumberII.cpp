class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i <= nums.size() - 3; i += 3) {
            if (nums[i] != nums[i + 1] || nums[i] != nums[i + 2]) {
                return nums[i];
            }
        }

        return nums[nums.size() - 1];
    }
};