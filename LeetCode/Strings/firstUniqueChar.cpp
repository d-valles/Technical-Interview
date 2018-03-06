class Solution {
public:
    void createMap(string &s, unordered_map<char, int>& HM) {
        for (int i = 0; i < s.length(); i++) {
            char current = s[i];
            HM[current]++;
        }
    }
    
    int firstUniqChar(string s) {
        unordered_map<char, int> HM; 
        createMap(s,HM);
        for (int i = 0; i < s.length(); i++) {
            char current = s[i];
            if (HM[current] == 1) return i;
        }
        return -1;
    }
};