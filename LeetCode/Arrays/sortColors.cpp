class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0;
        int blue = nums.size() - 1;
        
        for(int i = red; i < nums.size(); i++) {           
            if (nums[i] == 0) {
                swap(nums[i], nums[red]);
                red++;
            }
        }
        
        for(int i = blue; i >= 0; i--) {
            if (nums[i] == 2) {
                swap(nums[i], nums[blue]);
                blue--;
            }
        }
        
    }
};