class Solution {
public:
    // New String
    string usingPointer (string s) {
        string word = "";        
        for (int i = 0; i < s.size(); i++) {
            if (!word.empty() && s[i] == '#') {
                word.pop_back();
            } else if (s[i] != '#') {
                word.push_back(s[i]);
            }
        }
        return word;
    }

    // O(n) space
    string newString (string s) {
        stack<char> charStack;
        string word = "";
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '#' && !charStack.empty()) {
                charStack.pop();
            } else {
                charStack.push(s[i]);
            }
        }
        
        while(!charStack.empty()) {
           word.push_back(charStack.top());
            charStack.pop();
        }
        return word;
    }
    
    
    bool backspaceCompare(string S, string T) {
        if (newString(S) == newString(T)) return true;
        return false;
    }
};