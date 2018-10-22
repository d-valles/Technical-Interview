class Solution {
public:
    // 1 1 1 = 2
    // 1 2 3
    // 1 2 3
    
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> H;
        int numOfArrays = 0;
        int sum = 0;
        H.emplace(0,1);
        
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (H.find(sum - k) != H.end()) numOfArrays += H[sum - k];
            H[sum]++;
        }
        
        return numOfArrays;
    }
};