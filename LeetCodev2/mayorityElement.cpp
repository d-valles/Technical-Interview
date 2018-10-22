int Solution::majorityElement(const vector<int> &A) {
    int count = 1;
    int element = A[0];
    for (int i = 1; i < A.size(); i++) {
        if (element == A[i]) {
            count++;
        } else {
            count--;
        }
        
        if (count == 0) {
            count = 1;
            element = A[i];
        }
    }
    
    return element;
}
