vector<vector<int> > Solution::prettyPrint(int A) {

	int L = A * 2 - 1;

	vector<int> row(L, A);
	vector<vector<int>> ansMatrix(L , row);

	for(int i = 1; i < A; i++) {

		int number = A - i;
		vector<int> tempRow = ansMatrix[i - 1];
		
		for(int j = i; j < L - i; j++) {
			tempRow[j] = number;
		}

		ansMatrix[i] = tempRow;
		ansMatrix[L - i - 1] = tempRow;
	}

	return ansMatrix;
}