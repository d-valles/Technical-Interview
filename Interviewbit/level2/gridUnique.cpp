bool valid(int a, int A) {
    if (a < 0 || a >= A) return false;
    return true;
}

int Solution::uniquePaths(int A, int B) {
    
    if(!A || !B) return 0;
    
    vector<int> row(B, 0);
    vector<vector<int>> matrix(A, row);
    
    matrix[0][0] = 1;
    
    for(int i = 0; i < A; i++) {
        for(int j = 0; j < B; j++) {
            if(valid(i - 1, A)) matrix[i][j] += matrix[i-1][j];
            if(valid(j - 1, B)) matrix[i][j] += matrix[i][j-1];
        }
    }

    return matrix[A - 1][B - 1];
}