vector<int> Solution::prevSmaller(vector<int> &A) {
    vector<int> answer (A.size(), -1);
    
    stack<int> S;
    
    for (int i = 0; i < A.size(); i++) {
        while(!S.empty() && A[i] <= S.top()) {
            S.pop();
        }
        
        if (!S.empty()) {
            answer[i] = S.top();
        }
        
        S.push(A[i]);
    }
    
    return answer;
}