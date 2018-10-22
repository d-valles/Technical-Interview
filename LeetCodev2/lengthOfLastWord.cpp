int Solution::lengthOfLastWord(const string A) {
    int answer = 0;

    for (int i = A.size() - 1; i>= 0; i--) {
        if (A[i] == ' ' && answer) {
            return answer;
        } else if (A[i] != ' ') {
            answer++;
        }
    }
    
    return answer;
}