vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
    int ptrA = 0;
    int ptrB = 0;
    vector<int> answer;
    
    while (ptrA < A.size() && ptrB < B.size()) {
        if (A[ptrA] == B[ptrB]) {
            answer.push_back(A[ptrA]);
            ptrA++;
            ptrB++;
        } else if (A[ptrA] > B[ptrB]) {
            ptrB++;
        } else {
            ptrA++;
        }
    }
    
    return answer;
}