class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        vector<string> row(500, "");
        vector<string> col(500, "");
        
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].size(); j++) {
                row[i] += words[i][j];
                col[j] += words[i][j];
            }
        }
        
        for (int i = 0; i < row.size(); i++) {
            if (row[i] != col[i]) return false;            
        }
        return true;
    }
};