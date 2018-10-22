class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() > haystack.size()) return -1;
        if (haystack == needle) return 0;
        
        int l = needle.size();
        
        for (int i = 0; i <= haystack.size() - l; i++) {
            if (needle == haystack.substr(i, l)) {
                return i;
            }
        }
        return -1;
    }
};