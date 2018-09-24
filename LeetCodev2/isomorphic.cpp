class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;
        
        unordered_map<char, char> M;
        unordered_set<char> S;
        
        for (int i = 0; i < s.size(); i++) {
            char current = s[i];
            
            if (M.find(current) != M.end() && M[current] != t[i]) {
                return false;   
            }
            else if(M.find(current) == M.end() && S.find(t[i]) != S.end()) {
                return false;
            }
            else {
                M.emplace(s[i], t[i]);
                S.emplace(t[i]);
            }
        }
        
        return true;
    }
};