/*
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
*/
class Solution {
public:
    int findLast(vector<int>&nums, int target) {
        int start = 0;
        int end = nums.size() - 1; 

        while (start <= end) {
            int mid = (end + start) / 2;

            if ((mid == 0 || nums[mid - 1] != target) && nums[mid] == target) {
                return mid;
            } else if (nums[mid] >= target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        
        return -1;
    }

    int findFirst(vector<int>&nums, int target) {
        int start = 0;
        int end = nums.size() - 1; 

        while (start <= end) {
            int mid = (end + start) / 2;

            if ((mid == nums.size() - 1 || nums[mid + 1] != target) && nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        
        return -1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int f = findFirst(nums, target);
        int l = findLast(nums, target);
        return {l, f};
    }
};