class Solution {
public:
    // sort
    vector<int> twoSumSortedArray(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end())

        int start = 0;
        int end = nums.end();

        while(start < end) {
            int sum = nums[start] + nums[end];
            if (sum == target) {
                return {nums[start], nums[end]};
            } else if (sum > target) {
                end--;
            }else {
                start++;
            }
        }
        
        return {};
    }
    // desordenado
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hashMap;
        int lookingFor = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            lookingFor = target - nums[i] ;
            
            if(hashMap.find(lookingFor) != hashMap.end()) {
                 return { hashMap[lookingFor], i };      
            } else {
                hashMap.emplace(nums[i], i);
            }
        }
        
        return {0,0};
    }
};