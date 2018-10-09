bool isNegative (int a) {
    return a < 0;
}

void checkLonger(long long &maxSum, long long &sum, vector<int>& answer, vector<int>& actual) {
     if (maxSum < sum || (maxSum == sum && answer.size() < actual.size())) {
        maxSum = sum;
        answer = actual;
    } 
}

vector<int> Solution::maxset(vector<int> &A) {
    vector<int> answer;
    vector<int> actual;
    long long maxSum = -1;
    long long sum = 0;
    
    for (int i = 0; i < A.size(); i++) {
        int current = A[i];
        
        if (!isNegative(current)) {
            sum += current;
            actual.push_back(current);
        } else {
            checkLonger(maxSum, sum, answer, actual);
            sum = 0;
            actual.clear();
        }
    }
    
    checkLonger(maxSum, sum, answer, actual);
    
    return answer;
}
