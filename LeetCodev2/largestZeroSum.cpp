// 1 2 -2 4 -4
// 1 3 1 5 1

// 0 2 -2
// 0 2 0

//[ 1, 2, -2, 4, -4 ]
//  1  3  1  5    1


vector<int> Solution::lszero(vector<int> &A) {
    vector<int> answer;
    unordered_map<int,int> H;
    int sum = 0;
    
    for (int i = 0; i < A.size(); i++) {
        int current = A[i];
        
        if (H.find(sum) == H.end()) {
            H.emplace(sum, i);
        } else {
            int oldIndex = H[sum];
            vector<int> temporal(A.begin() + oldIndex, A.begin() + i);
            if (temporal.size() > answer.size()) {
                answer = temporal;
            }
        }
        
        sum += current;
    }
    
    if (H.find(sum) != H.end()) {
        int oldIndex = H[sum];
        vector<int> temporal(A.begin() + oldIndex, A.end());
        if (temporal.size() > answer.size()) {
            answer = temporal;
        }  
    }
    
    return answer;
}
