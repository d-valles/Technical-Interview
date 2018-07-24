class Solution {
public:
    void reverseW (string &s, int i, int j) {
        while (i <= j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
    
    void reverseWords(string &s) {
        
        bool isWord = false;
        int firstOccurence = -1;
        
        reverse(s.begin(), s.end());
        
        for (int i = 0; i < s.size(); i++) {
            if (!isWord && s[i] != ' ') {
                firstOccurence = i;
                isWord = true;
            } else if (isWord && (s[i] == ' ' || i == s.size() - 1)) {
                i == s.size() - 1 ? reverseW(s, firstOccurence, i) : reverseW(s, firstOccurence, i - 1);
                isWord = false;
            }
        }
    }
};