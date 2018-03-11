class Solution {
public:
    void bottomUp(vector<int>&nums, vector<vector<int>> &subs) {
        for(int i = 0; i < nums.size(); i++) {       
            int l = subs.size();
            
            for(int j = 0; j < l; j++) {
                vector<int> newSet = subs[j];
                newSet.push_back(nums[i]);
                subs.push_back(newSet);
            }
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs;
        vector<int> set;
        subs.push_back(set);
        bottomUp(nums, subs);
        return subs;
    }
};