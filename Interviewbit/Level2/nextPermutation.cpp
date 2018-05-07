int findTarget(const vector<int>& A) {
   int target = -1;
   
   for (int i = A.size() - 2; i >= 0; i--) {
        if(A[i+1] > A[i]) return i;
   }

   return target;
}

void Solution::nextPermutation(vector<int> &A) {
    if (!A.size() || A.size() == 1) return;
    
    int target = findTarget(A);
    int smallest = A[A.size() - 1];
    
    if (target == -1) {
        sort(A.begin(), A.end());
        return;
    }
    
    // find smallest number
   for (int i = target + 1; i < A.size(); i++) {
        if(A[i] > A[target]) {
            smallest = i;
        }
   }
    
    swap(A[target], A[smallest]);
    sort(A.begin() + target + 1, A.end());
    return;
}