class Solution {
public:
    
    bool isValid(vector<vector<char>>& board, int row, int col) {
        if (board.size() - 1 < row || 0 > row || board[row].size() - 1 < col || 0 > col) {
            return false;
        }
        return true;
    }
    
    bool searchDFS (vector<vector<char>>& board, string word, int row, int col, int position) {
        if (!isValid(board, row, col) || board[row][col] != word[position]) {
            return false;
        }
        
        if (position == word.length() - 1) return true;
        board[row][col] = '*';
        
        bool foundWord = searchDFS(board, word, row - 1, col, position + 1) || 
                searchDFS(board, word, row + 1, col, position + 1) ||
                searchDFS(board, word, row, col - 1, position + 1) ||
                searchDFS(board, word, row, col + 1, position + 1);              
        
        board[row][col] = word[position];     
        return foundWord;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (word[0] == board[i][j]) {
                   if (searchDFS(board, word, i, j, 0)) return true;
                }
                continue;
            }
        }
        return false;
    }
};