/*
	How can we reuse code without making it messy?
*/
int findFirst(const vector<int> &A, int target) {
	int s = 0;
	int e = A.size() -1;

	while (s <= e) {
		int mid = (s + e) / 2;

		if (A[mid] == target && (mid == 0 || A[mid -1] != target)) {
			return mid;
		}else if (A[mid] > target || A[mid] == target) {
			e = mid - 1;
		} else {
			s = mid + 1;
		}
	}

	return -1;
}

int findLast(const vector<int>&A, int target) {
	int s = 0;
	int e = A.size() - 1;

	while (s <= e) {
		int mid = (s + e) / 2;

		if (A[mid] == target && (mid == A.size() -1 || A[mid + 1] != target)) {
			return mid;
		}else if (A[mid] > target) {
			e = mid - 1;
		} else {
			s = mid + 1;
		}
	}

	return -1;
}

int Solution::findCount(const vector<int> &A, int B) {
	int firstOccurence = findFirst(A, B);
	int lastOccurence = findLast(A, B);

	return (firstOccurence == -1) ? 0 : lastOccurence - firstOccurence + 1;
}