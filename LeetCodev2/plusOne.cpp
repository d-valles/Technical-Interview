class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        int i = 0;
        int carry = 1;
        while (i < digits.size() && carry) {
            digits[i] = carry + digits[i];
            
            carry = digits[i] >= 10 ? 1 : 0;
            digits[i] %= 10;
            i++;
        }

        if (carry) {
            digits.push_back(1);
        }
        
        reverse(digits.begin(), digits.end());
        return digits;
    }
};