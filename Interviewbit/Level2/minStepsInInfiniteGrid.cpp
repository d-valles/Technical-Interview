int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    
    int steps = 0;
    if ( B.size() == 0 ) return steps;
    
    int x = A[0];
    int y = B[0];
    
    for(int i = 1; i < B.size(); i++) {
        
        int diffX = abs(A[i] - x);
        int diffY = abs(B[i] - y);
        
        steps += max(diffX, diffY);
        
        x = A[i];
        y = B[i];
    }
    
    return steps;
}