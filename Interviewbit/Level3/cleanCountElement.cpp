int bs(const vector<int>&A, int target, bool first) {
	int s = 0;
	int e = A.size() - 1;

	int result = -1;

	while (s <= e) {
		int mid = (s + e) / 2;

		if (A[mid] == target) {
			result = mid;

			if (first) {
				e = mid - 1;
			} else {
				s = mid + 1;
			}

		}else if (A[mid] > target) {
			e = mid - 1;
		} else {
			s = mid + 1;
		}
	}

	return result;
}

int Solution::findCount(const vector<int> &A, int B) {
	int firstOccurence = bs(A, B, true);
	int lastOccurence = bs(A, B, false);

	return (firstOccurence == -1) ? 0 : lastOccurence - firstOccurence + 1;
}