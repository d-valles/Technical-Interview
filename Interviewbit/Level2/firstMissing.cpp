int Solution::firstMissingPositive(vector<int> &A) {
	if (!A.size()) return 1;

	for (int i = 0; i < A.size(); i++) {
		// swap to place
		int current  = A[i];

		while (current > 0 && current <= A.size() && current != A[current - 1]) {
			swap(A[i], A[current - 1]);
			current = A[i];
		}
	}

	for (int i = 0; i < A.size(); i++) {
		if (A[i] != i + 1) return i + 1;
	}

	return A.size() + 1;
}