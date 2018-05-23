int Solution::isPalindrome(string A) {
    int start = 0;
    int end = A.size() - 1;

    if(A.size() == 0 || A.size() == 1) return 1;

    while (start <= end) {
        while(start < end && !isalnum(A[start])) {
            start++;
        }
        while(start < end && !isalnum(A[end])) {
            end--;
        }
        
        if(start >= end) return 1;
        
        if (tolower(A[start]) != tolower(A[end])) return 0;
        start++;
        end--;
    }
    return 1;
}
