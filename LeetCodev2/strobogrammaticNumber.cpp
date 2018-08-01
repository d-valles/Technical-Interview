class Solution {
public:
    bool checkIfMove(string& num, int start, int end) {
        if (num[end] == '0' && num[start] == '0') {
            return true;
        } else if (num[end] == '1' && num[start] == '1') {
            return true;
        } else if (num[end] == '8' && num[start] == '8') {
            return true;
        } else if (num[end] == '6' && num[start] == '9') {
            return true;
        } else if (num[end] == '9' && num[start] == '6') {
            return true;
        }
        
        return false;
    }
    
    bool isStrobogrammatic(string num) {
        int start = 0;
        int end = num.size() - 1;
        
        
        while (start <= end) {
            int current = num[end];

            if (checkIfMove(num, start, end)) {
                start++;
                end--;
            } else {
                return false;
            }
        }
        
        return true;
    }
};