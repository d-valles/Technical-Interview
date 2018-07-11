class Solution {
public:
    string addStrings(string num1, string num2) {
        
        string newNumber = "";
        
        int ptr1 = num1.size() - 1;
        int ptr2 = num2.size() - 1;
        
        int carry = 0;
        
        while (carry || ptr1 >= 0 || ptr2 >= 0) {
            
            int sum = 0;
            int digit1 = 0;
            int digit2 = 0;
            
            if (ptr1 >= 0) {
                digit1 = num1[ptr1] - '0';
                ptr1--;
            }
            
            if (ptr2 >= 0) {
                digit2 = num2[ptr2] - '0';
                ptr2--;
            }
            
            sum += (digit1 + digit2 + carry) % 10;
            newNumber.push_back(sum + '0');
            
            carry = (digit1 + digit2 + carry) >= 10 ? 1 : 0;
        }
        reverse(newNumber.begin(), newNumber.end());
        return newNumber;
    }
};