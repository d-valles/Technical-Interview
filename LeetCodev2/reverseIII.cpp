class Solution {
public:
    string reverseWords(string s) {
        int start = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ' || i == s.size() - 1) {
                if (i == s.size() - 1) i++;
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }
        return s;
    }
};