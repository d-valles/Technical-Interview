class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> hMap;
        
        for (int i = 0; i < nums.size(); i++) {
            int current = nums[i];
            if(hMap[current]++ >= nums.size()/2) return current;
        }
        
        return 0;
    }
};