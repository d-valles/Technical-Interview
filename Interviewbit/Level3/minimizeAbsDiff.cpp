int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    
    int ia, ib, ic = 0;
    int minV = INT_MAX;
    
    while (ia < A.size() && ib < B.size() && ic < C.size()) {
        
        int maxDiff = abs( max(C[ic], max(A[ia], B[ib])) - min(C[ic], min(A[ia], B[ib])) );
        minV = min(maxDiff, minV);
        
        if (ia < A.size() && A[ia] <= B[ib] && A[ia] <= C[ic]) {
            ia++;
        }
        else if (ib < B.size() && B[ib] <= A[ia] && B[ib] <= C[ic]) {
            ib++;
        }
        else if (ic < C.size() && C[ic] <= A[ia] && C[ic] <= B[ib]) {
            ic++;
        }
    }
    return minV;
}
