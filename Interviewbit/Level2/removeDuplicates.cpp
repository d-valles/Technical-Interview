int Solution::removeDuplicates(vector<int> &A) {
    int pos = 0;
    int current = 0;
    
    while (current < A.size()) {
        if (A[pos] != A[current]) {
            A[++pos] = A[current];
        }
        current++;
    }
    
    return pos + 1;
}
/// 1 2 3 4 5 6 6 7 7
// 1 2 3 4 5 6 7 