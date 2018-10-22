class Solution {
public:
    int getSum(int n) {
        int sum = 0;
        for(int i = 0; i <= n; i++) {
            sum += i;
        }
        return sum;
    }
    
    int missingNumber(vector<int>& nums) {
        int count = 0;
        int sum = getSum(nums.size());
        
        for (int i = 0; i < nums.size(); i++) {
            count += nums[i];
        }
        
        return sum - count;
    }
};