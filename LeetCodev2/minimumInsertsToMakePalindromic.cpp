int Solution::solve(string A) {
    int start = 0;
    int end = A.size() - 1;
    int tend = end;
    
    while (start < tend) {
        
        if (A[start] == A[tend]) {
           start++;
           tend--;
        } else {
           start = 0;
           tend = --end;
        }
    }
    
    return A.size() - (end+1);
}
