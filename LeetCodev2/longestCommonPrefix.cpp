class Solution {
public:
    string  updatePrefixOfWord(string prefix, string word) {
        int start = 0;
        
        while (start < prefix.length() && start < word.length() && prefix[start] == word[start]) {
            start++;
        }
        return prefix.substr(0, start);
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        
        string prefix = "";
        
        if (!strs.size()) return prefix;
        
        prefix = strs[0];
        
        for (int i = 1; i < strs.size(); i++) {
            prefix = updatePrefixOfWord(prefix, strs[i]);
        }
        
        return prefix;
    }
};