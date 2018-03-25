class Solution {
public:
    unordered_set<char> jewels(string& J) {
        unordered_set<char> sJewels;
        for (int i = 0; i < J.size(); i++) {
            sJewels.emplace(J[i]);
        }
        return sJewels;
    }
    
    int getNumJ(string& S, unordered_set<char>& sJewels) {
        int totalJ = 0;
        for (int i = 0; i < S.size(); i++) {
            char current = S[i];
            if(sJewels.find(S[i]) != sJewels.end()) totalJ++;
        }
        return totalJ;
    }
    
    int numJewelsInStones(string J, string S) {
        unordered_set<char> sJewels = jewels(J);
        return getNumJ(S, sJewels);
    }
};