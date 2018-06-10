int Solution::threeSumClosest(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    
    int ans = INT_MAX;
    int ansAbs = INT_MAX;
    
    for (int i = 0; i < A.size(); i++) {
        int current = A[i];
        
        int start = i + 1;
        int end = A.size() - 1;
        
        while (start < end) {
            int sum = A[start] + A[end] + current;
            
            if (abs(B - sum) < ansAbs) {
                ans = sum;
                ansAbs = abs(B-sum);
            }
            
            
            if (sum > B) {
                end--;
            } else {
                start++;
            }
        }
    } 
    return ans;
}
