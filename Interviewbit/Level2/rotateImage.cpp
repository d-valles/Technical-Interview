void Solution::rotate(vector<vector<int> > &A) {
	int n = A.size();

	int s = 0;
	int e = n - 1;
    
    for (int i = 0; i < n/2; i++) {
        for (int j = i; j < e - i; j++) {
            swap(A[i][j], A[j][e - i]);
            swap(A[i][j], A[e - i][e - j]);
            swap(A[i][j], A[e - j][i]);
        }
    }
}
