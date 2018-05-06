/*
Find out the maximum sub-array of non negative numbers from an array.
The sub-array should be continuous. That is, a sub-array created by choosing the second and fourth element and skipping the third element is invalid.

Maximum sub-array is defined in terms of the sum of the elements in the sub-array. Sub-array A is greater than sub-array B if sum(A) > sum(B).

Example:

A : [1, 2, 5, -7, 2, 3]
The two sub-arrays are [1, 2, 5] [2, 3].
The answer is [1, 2, 5] as its sum is larger than [2, 3]
NOTE: If there is a tie, then compare with segment's length and return segment which has maximum length
NOTE 2: If there is still a tie, then return the segment with minimum starting index
*/
vector<int> Solution::maxset(vector<int> &A) {
    vector<int> maxSubArray;
    long long int maxCount = 0;
    
    if (!A.size()) return maxSubArray;
    
    vector<int> currentSub;
    long long int count = 0;
    
    for (int i = 0; i < A.size(); i++) {
        
        if (A[i] >= 0) {
            currentSub.push_back(A[i]);
            count += A[i];
        } else {
            currentSub.clear();
            count = 0;
        }
        
        if (count > maxCount) {
            maxSubArray = currentSub;
            maxCount = count;
        }
        
        if (count == maxCount && currentSub.size() > maxSubArray.size()) {
            maxSubArray = currentSub;
            maxCount = count;
        }
    }
    
    return maxSubArray;
}
