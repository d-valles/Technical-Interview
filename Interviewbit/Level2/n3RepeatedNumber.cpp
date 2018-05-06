//Second solution Boyer Voting algorithm
//Second solution Boyer Voting algorithm
int validateCandidate(const vector<int>& A, int candidate1, int candidate2) {

	int count1 = 0;
	int count2 = 0;

	for (int i = 0; i < A.size(); i++) {
		if (A[i] == candidate1) count1++;
		if (A[i] == candidate2) count2++;
	}

	if (count1 > A.size()/3) return candidate1;
	if (count2 > A.size()/3) return candidate2;

	return -1;
}

vector<int> getCandidate(const vector<int>& A) {
	int count1 = 0;
	int candidate1 = 0;

	int count2 = 0;
	int candidate2 = 0;

	for (int i = 0; i < A.size(); i++) {
		if (count1 > 0 && candidate1 == A[i]) {
			count1++;
		} else if (count2 > 0 && A[i] == candidate2) {
			count2++;
		} else if (count1 == 0) {
			candidate1 = A[i];
			count1 = 1;
		} else if (count2 == 0) {
		    candidate2 = A[i];
			count2 = 1;
		} else {
		    count1--;
		    count2--;
		}
	}

	vector<int> candidates = {candidate1, candidate2};
	return candidates;
}

int Solution::repeatedNumber(const vector<int> &A) {
	vector<int> candidates = getCandidate(A);
	return validateCandidate(A, candidates[0], candidates[1]);
}
