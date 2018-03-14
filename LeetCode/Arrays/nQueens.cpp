/*
    We can use extra memory to store states of the board and decrease runtime when validating position.
*/
class Solution {
public:
   vector<string> createBoard(int n) {
        string row (n, '.');
        vector<string> rows(n, row);
        return rows;
    }
    
    bool validateTop(vector<string>& board, int i, int j) {
        for(int ii = i - 1; ii >= 0; ii--) {
            if(board[ii][j] == 'Q') return false;
        }
        return true;
    }

    bool validateTR(vector<string> &board, int i, int j) {
        for(int ii = i - 1,  jj = j + 1; ii >= 0 && jj < board[ii].size(); ii--, jj++) {
            if(board[ii][jj] == 'Q') return false;
        }
        return true;
    }

    bool validateTL(vector<string> &board, int i, int j) {
        for(int ii = i - 1, jj = j + 1; ii >= 0 && jj >= 0; ii--, jj--) {
            if(board[ii][jj] == 'Q') return false;
        }
        return true;
    }
    
    bool check(vector<string> &board, int i, int j) {
        return validateTop(board,i,j) && validateTL(board,i,j) && validateTR(board, i, j);
    }
    
    void helper(vector<vector<string>> &solutions, vector<string>&board, int row, int queens) {
        if(queens == board.size()) {
            solutions.push_back(board);
            return;
        }
        
        for (int j = 0; j < board[row].size(); j++) {
            if (check(board, row, j)) {
                board[row][j] = 'Q';
                helper(solutions, board, row + 1, queens + 1);
                board[row][j] = '.';
            }
        }
        
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> solutions;
        vector<string> board = createBoard(n);
        helper(solutions, board, 0, 0);
        return solutions;
    }
};