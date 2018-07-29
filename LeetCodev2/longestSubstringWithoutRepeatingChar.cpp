class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> hashMap;
        
        int longestSubstring = 0;
        
        int start = 0;
        int end = 0;
        
        while (end < s.length() && start < s.length()) {
            int current = s[end];
            
            if (hashMap.find(current) == hashMap.end()) {
                hashMap.emplace(current);
                end++;
                longestSubstring = max(longestSubstring, end - start);                         
            } else {
                hashMap.erase(s[start]);
                start++;
            }
        }
        
        return longestSubstring;
    }
};