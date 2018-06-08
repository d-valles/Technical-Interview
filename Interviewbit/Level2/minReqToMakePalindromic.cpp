bool isPalindrome(string A, int end) {
    int start = 0;
    
    while (start < end) {
        if (A[start++] != A[end--]) {
            return false;
        }
    }
    return true;
}

int Solution::solve(string A) {
    int end = A.size() - 1;
    while (!isPalindrome(A, end) && end >= 0) {
        end--;
    }
    return A.size() - 1 - end;
}
