vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    vector<int> ans;
    
    if(A.size() == 0) return ans;
    
    int L = 0; 
    int R = A[0].size() - 1;
    int T = 0;
    int B = A.size() - 1;
    
    while(L <= R && T <= B) {
        
        for (int i = L; i <= R; i++) {
            ans.push_back(A[T][i]);
        }
        T++;
        
        for (int i = T; i <= B; i++) {
            ans.push_back(A[i][R]);
        }
        R--;
        
        if (T <= B) {
            for (int i = R; i >= L; i--) {
                ans.push_back(A[B][i]);        
            }
            B--;
        }
        
        if (L <= R) {
            for (int i = B; i >= T; i--) {
                ans.push_back(A[i][L]);        
            }
            L++;
        }
    }
    
    return ans;
}
