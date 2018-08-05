class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = 0;
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[n] != nums[i]) {
                n++;
                swap(nums[n], nums[i]);
            }
        }
        return nums.size() ? n + 1 : n;
    } 
};