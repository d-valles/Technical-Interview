/
/* Recursive Solution
class Solution {
public:
    int helper(string &s, int k) {
        if (k == 0) return 1;
        
        int position = s.length() - k;
        
        if (s[position] == '0') return 0;
        
        int result = helper(s, k - 1);
        
        if (k >= 2 && stoi(s.substr(position, 2)) <= 26) {
            result += helper(s, k - 2);
        }
        
        return result;
    }
    
    int numDecodings(string s) {
        return helper(s, s.length());
    }
};
*/
class Solution {
public:
    int helper(string &s, int k, vector<int>& memo) {
        if (k == 0) return 1;
        
        int position = s.length() - k;
        
        if (s[position] == '0') return 0;
        
        if (memo[k] != 0) return memo[k];
        
        int result = helper(s, k - 1, memo);
        
        if (k >= 2 && stoi(s.substr(position, 2)) <= 26) {
            result += helper(s, k - 2, memo);
        }
        
        memo[k] = result;
        return result;
    }
    
    int numDecodings(string s) {
        vector<int> memo(s.length() + 1, 0);
        return helper(s, s.length(), memo);
    }
};