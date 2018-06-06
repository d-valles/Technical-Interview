vector<int> Solution::findPerm(const string A, int B) {
    int start = 1;
    int end = B;
    
    vector<int> ans;
    
    for (int i = 0; i < A.size(); i++) {
        
        if (A[i] == 'D') {
            ans.push_back(end);
            end--;
        } else if (A[i] == 'I') {
            ans.push_back(start);
            start++;
        }
        
    }
    ans.push_back(start);
    return ans;
}
// 1 2 3 4 5 6

//I I D D I