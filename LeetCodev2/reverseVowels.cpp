class Solution {
public:
    bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ? true : false;
    }
    
    string reverseVowels(string s) {
        int start = 0;
        int end = s.length() - 1;
        
        while (start <= end) {
            while(start <= end && !isVowel(s[start])) {
               start++;
            }
            while(start <= end && !isVowel(s[end])) {
               end--;
            }
            if(isVowel(s[start]) && isVowel(s[end])) swap(s[start], s[end]);
            start++;
            end--;
        }
        return s;
    }
};