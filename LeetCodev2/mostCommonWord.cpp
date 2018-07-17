class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> hashMap;
        unordered_set<string> bans;
        
        int iMax = 0;
        string sWord = "";
        
        for (int i = 0; i < banned.size(); i++) {
            bans.emplace(banned[i]);
        }

        string currentWord = "";
        for (int i = 0; i < paragraph.size(); i++) {
            char current = tolower(paragraph[i]);   
            
            if (isalpha(current)) {
              currentWord += current;
            } else if (!isalpha(current) && currentWord.length() > 0 && bans.find(currentWord) == bans.end()) {
                hashMap[currentWord] += 1;
                
                if (hashMap[currentWord] > iMax) {
                    iMax = hashMap[currentWord];
                    sWord = currentWord;
                }
                
                currentWord = "";
                
            } else {
                currentWord = "";
            }
        }
        return !sWord.length() ? currentWord : sWord;
    }
};