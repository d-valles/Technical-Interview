class Solution {
public:
    bool checkForDiff(vector<int>& letters) {
        for (int i = 0; i < letters.size(); i++) {
            if (letters[i] != 0) return false;
        }
        return true;
    }
    
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        
        vector<int> letters (26, 0);
        
        for (int i = 0; i < s.size(); i++) {
            int current = s[i] - 'a';
            letters[current] += 1;
        }
        
        for (int i = 0; i < t.size(); i++) {
            int current = t[i] - 'a';
            letters[current] -= 1;
        }
        
        return checkForDiff(letters);
    }
};