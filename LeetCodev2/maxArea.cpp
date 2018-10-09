int Solution::maxArea(vector<int> &A) {
    int start = 0;
    int end = A.size() - 1;
    int answer = 0;
    
    while (start < end) {
        int b = end - start;
        int h = min(A[start], A[end]);
        int current = h * b;
        
        
        answer = max(current, answer);
        
        
        if (A[start] < A[end]) {
            start++;
        } else {
            end--;
        }
    }
    
    return answer;    
}