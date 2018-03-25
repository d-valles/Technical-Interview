class Solution {
public:
	void convertValue(vector<int>& nums) {
		for(int i = 0; i < nums.size(); i++) {
			int number = abs(nums[i]) - 1;
			if (nums[number] > 0) {
                nums[number] = nums[number] * -1;
            }
		}
	}

	vector<int> findNumbers(vector<int>&nums) {
		vector<int> disappearN;
		for(int i = 0; i <nums.size(); i++) {
			if(nums[i] > 0) {
				disappearN.push_back(i+1);
			}
		}
        return disappearN;
	}

    vector<int> findDisappearedNumbers(vector<int>& nums) {
    	convertValue(nums);
        return findNumbers(nums);
    }
};

/*
int i = 0
[2, 3 , 3, 1]
[3, 2, 1, 1]
[1,2,3,1]
*/