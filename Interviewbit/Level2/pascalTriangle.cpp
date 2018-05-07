vector<vector<int> > Solution::generate(int A) {
	vector<vector<int>> pascal;
	vector<int> row = {1};

	if (A == 0) return pascal;
	pascal.push_back(row);

	for (int i = 1; i < A; i++) {
		vector<int> current;
		int prev = 0;
		for (int j = 0; j < pascal[i-1].size(); j++) {
		    
            current.push_back(pascal[i-1][j] + prev);
            prev = pascal[i-1][j];
            
            if (j == pascal[i-1].size() - 1) {
                current.push_back(1);
            }
		}
		pascal.push_back(current);
	}
	return pascal;
}
