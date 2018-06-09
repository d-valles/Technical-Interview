void increaseA(vector<int>&A, int numsInB) {
    for (int i = 0; i < numsInB; i++) {
        A.push_back(INT_MIN);
    }
}

void Solution::merge(vector<int> &A, vector<int> &B) {
    int endA = A.size() - 1;
    int endB = B.size() - 1;
    
    increaseA(A, B.size());
    int end = A.size() - 1;
  
    while (end >= 0) {
        
        if (endA < 0) {
            A[end] = B[endB--];
        } else if (endB < 0) {
            A[end] = A[endA--];
        } else if (A[endA] >= B[endB]) {
            A[end] = A[endA--];
        } else {
            A[end] = B[endB--];
        }
        end--;
    }
}

// -4 -2 -2 3 
// -2 -2 
