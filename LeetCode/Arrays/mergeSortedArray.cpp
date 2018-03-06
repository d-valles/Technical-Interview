class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) return;
        int ptr1 = m - 1;
        int ptr2 = n - 1;
        int start = m + n - 1;
    
        while(start >= 0) {
           if (ptr1 < 0) {
               nums1[start] = nums2[ptr2];
               ptr2--;
           }
           else if (ptr2 < 0) {
               nums1[start] = nums1[ptr1];
               ptr1--;
           }
           else if (nums1[ptr1] < nums2[ptr2]) {
               nums1[start] = nums2[ptr2];
               ptr2--;
           }
           else {
               nums1[start] = nums1[ptr1];
               ptr1--;
           }
           start--;
        }
    }
};