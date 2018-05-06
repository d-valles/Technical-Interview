class Solution {
public:
	int validateCandidate(vector<int>& nums, int candidate) {
		if (candidate == 0) return 0;

		int count = 0;

		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == candidate) count++;
		}

		return nums.size()/2 < count ? candidate : -1;
	}

	int getCandidate(vector<int>& nums) {
		int count = 0;
		int candidate = 0;

		for (int i = 0; i < nums.size(); i++) {
			if (count == 0) {
				candidate = nums[i];
				count++;
			} else if (nums[i] == candidate) {
				count++;
			} else {
				count--;
			}
		}

		return candidate;
	}

    int majorityElement(vector<int>& nums) {
    	int candidate = getCandidate(nums);
    	return validateCandidate(nums, candidate);
    }
};