class Solution {
public:
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