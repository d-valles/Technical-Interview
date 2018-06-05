int Solution::maxSubArray(const vector<int> &A) {
    if (!A.size()) return 0;
    
    int maxSum = A[0];
    int sum = A[0];
    
    for (int i = 1; i < A.size(); i++) {
        int currentSum = A[i] + sum;
        sum = (currentSum > 0 && currentSum > A[i]) ? currentSum : A[i];
        maxSum = max(sum, maxSum);
    }
    
    return maxSum;
}
