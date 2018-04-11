vector<int> deleteZeroes(vector<int> answer) {
    int i = 0;
    while (i < answer.size() && answer[i] == 0) {
        i++;
    }
    vector<int> t(answer.begin()+i, answer.end());
    return t;
}

vector<int> Solution::plusOne(vector<int> &A) {
    vector<int> answer;
    
    int carry = 1;
    int number = 0;
    
    for (int i = A.size() - 1; i >= 0; i--) {
        int sum = A[i] + carry;
        number = (sum) % 10;
        answer.push_back(number);
        
        carry = (sum >= 10) ? 1 : 0;
    } 
    
    if (carry) {
        answer.push_back(1);
    }
    
    reverse(answer.begin(), answer.end());
    return deleteZeroes(answer);
}