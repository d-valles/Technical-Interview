class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        
        int max1 = INT_MIN;
        int max2 = INT_MIN;
        int max3 = INT_MIN;
        int min1 = INT_MAX;
        int min2 = INT_MAX;
        
        for (int i = 0; i < nums.size(); i++) {
           int current = nums[i];
            
           if (current <= min1) {
               min2 = min1;
               min1 = current;
           } else if (current <= min2) {
               min2 = current;
           }
            
           if (current >= max1) {
               max3 = max2;
               max2 = max1;
               max1 = current;
           } else if (current >= max2) {
               max3 = max2;
               max2 = current;
           } else if (current >= max3) {
               max3 = current;
           }
        }
        
        cout<< min1 << min2 << max1 << max2 << max3;
        
        return max(min1 * min2 * max1, max1 * max2 * max3);
    }
};