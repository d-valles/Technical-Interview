vector<int> Solution::getRow(int A) {
	vector<int> row = {1};

	if (A == 0) return row;

	for (int i = 0; i < A; i++) {
		vector<int> current;
		int prev = 0;
		for (int j = 0; j < row.size(); j++) {
		    
            current.push_back(row[j] + prev);
            prev = row[j];
            
            if (j == row.size() - 1) {
                current.push_back(1);
            }
		}
		row = current;
	}
	return row;
}
