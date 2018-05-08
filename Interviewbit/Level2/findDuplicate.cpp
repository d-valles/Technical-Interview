/*
Given a read only array of n + 1 integers between 1 and n, find one number that repeats in linear time using less than O(n) space and traversing the stream sequentially O(1) times.

Sample Input:

[3 4 1 4 1]
Sample Output:

1
If there are multiple possible answers ( like in the sample case above ), output any one.

If there is no duplicate, output -1
*/
// works but when you can modify your array.
int Solution::repeatedNumber(const vector<int> &A) {
	int i = 0;

	while (i < A.size()) {
		while (A[i] != i+1) {
			int num = A[i] - 1;

			if (A[i] == A[num]) {
				return A[i];
			} else {
				swap(A[num], A[i]);
			}
		}
		i++;
	}

	return -1;
}
