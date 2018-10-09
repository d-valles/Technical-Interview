class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        
        for (int i = 0; i < nums.size();) {
            
            int current = nums[i];
            nums[count] = current;
            count++;
            i++;
            
            if (i < nums.size() && nums[i] == current) {
                nums[count] = current;
                count++;
                i++;
            }
            
            while(i < nums.size() && nums[i] == current) {
                i++;
            }
        }
        
        return count;
    }
};