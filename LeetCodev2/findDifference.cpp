class Solution {
public:
    char findTheDifference(string s, string t) {
        int sum = 0;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i] - 'a';
            sum -= c;
        }
        
        for (int i = 0; i < t.size(); i++) {
            char c = t[i] - 'a';
            sum += c;
        }
        
        return sum + 'a';
    }
};