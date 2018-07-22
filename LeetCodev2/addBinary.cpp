class Solution {
public:
    string addBinary(string a, string b) {
        string newBinary;
        
        int carry = 0;
        int i = a.length() - 1;
        int j = b.length() - 1;
        
        while (i >= 0 || j >= 0 || carry) {
            
            int sum = carry;
            
            if (i >= 0) {
                sum += a[i] - '0';
                i--;
            }
            
            if (j >= 0) {
                sum += b[j] - '0';
                j--;
            }
            
            cout << sum <<", ";
            
            if(sum >= 2) {
                carry = 1;
                sum = sum % 2;
            }else {
                carry = 0;
            }            
            
            newBinary.push_back('0' + sum);
        }
        
        reverse(newBinary.begin(), newBinary.end());
        return newBinary;
    }
};