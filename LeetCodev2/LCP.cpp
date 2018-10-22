string Solution::longestCommonPrefix(vector<string> &A) {
    if (A.size() == 0) return "";
    
    string answer = A[0];
    
    for (int i = 1; i < A.size(); i++) {
        string current = A[i];
        int ptr1 = 0;
        
        while (ptr1 < answer.size() && ptr1 < current.size() && answer[ptr1] == current[ptr1]) {
            ptr1++;
        }
        
        answer = answer.substr(0, ptr1);
    }
    
    return answer;
}
