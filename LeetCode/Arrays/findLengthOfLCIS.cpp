class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        
        int maxSub = 1;
        int currentSub = 1;       
        int prev = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > prev) {
                currentSub++;
            } else {
                currentSub = 1;
            }
            
            maxSub = max(maxSub, currentSub);
            prev = nums[i];
        }
        
        return maxSub;
    }
};