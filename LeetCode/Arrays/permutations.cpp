class Solution {
public:
    void permuteBackTrack(vector<int> &nums, vector<vector<int>> &permutations, int position) {
        if (position == nums.size()) {
            permutations.push_back(nums);
            return;
        }
        
        for (int i = position; i < nums.size(); i++) {
            swap(nums[i], nums[position]);
            permuteBackTrack(nums, permutations, position + 1);
            swap(nums[i], nums[position]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permutations;
        if (nums.size() == 0) return permutations;
        
        permuteBackTrack(nums, permutations, 0);
        return permutations;
    }
};
