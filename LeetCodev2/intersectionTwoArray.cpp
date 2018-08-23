class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> answer;
        
        
        int n1 = 0;
        int n2 = 0;
        
        while (n1 < nums1.size() && n2 < nums2.size()) {
             if (nums1[n1] == nums2[n2]) {                 
                 int r = nums1[n1];
                 answer.push_back(r);
                 while(nums1[n1] == r) {
                     n1++;
                 }
                 while(nums2[n2] == r) {
                     n2++;
                 }
             } else if (nums1[n1] > nums2[n2]) {
                 n2++;
             } else {
                 n1++;
             }
        }
        
        return answer;
    }
};