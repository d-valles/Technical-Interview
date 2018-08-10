class Solution {
public:
    void validateNextJump(int i , vector<bool>& jump, vector<int>& nums) {
        for (int j = 1; j <= nums[i]; j++) {
            if (i + j < nums.size()) {
                jump[i + j] = true;
            }
        }
    }
    bool canJump(vector<int>& nums) {
        vector<bool> jump (nums.size(), false);
        jump[0] = true;
        
        for (int i = 0; i < nums.size(); i++) {
            if (jump[i]) {
                validateNextJump(i, jump, nums);
            }
        }
        
        return jump[nums.size() - 1] ? true : false;
    }
};