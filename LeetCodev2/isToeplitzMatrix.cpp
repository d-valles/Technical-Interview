class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int i = matrix.size() - 1;
        int j = 0;
        
        for (int i = matrix.size() - 1; i >= 0; i--) {
            if (!moveDiagonal(i + 1, 0 + 1, matrix)) return false;
        }
        
        for (int j = 0; j < matrix[0].size(); j++) {
            if (!moveDiagonal(0 + 1, j + 1, matrix)) return false;
        }
        
        return true;
    }
    
    bool moveDiagonal(int i, int j, vector<vector<int>> &matrix) {
        while(i < matrix.size() && j < matrix[i].size()) {
            if (matrix[i - 1][j - 1] != matrix[i][j]) {
                return false;
            }
            i++;
            j++;
        }
        return true;
    }
};