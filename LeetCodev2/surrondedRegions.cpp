class Solution {
public:
    bool isValid (vector<vector<char>>& board, int row, int col) {
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size()) return true;
        return false;
    }
    
    void dfs (vector<vector<char>>& board, int row, int col) {
        if (isValid(board, row, col) || board[row][col] != 'O') return;

        board[row][col] = '-';
        
        dfs(board, row + 1, col);
        dfs(board, row - 1, col);
        dfs(board, row, col + 1);
        dfs(board, row, col - 1);
    }
    
    void findBorder(vector<vector<char>>& board) {

        for (int i = 0; i < board[0].size(); i++) {
            if (board[0][i] == 'O') {
                dfs(board, 0, i);
            }
            
            if (board[board.size() - 1][i] == 'O') {
                dfs(board, board.size() - 1, i);
            }
        }
        
        for (int i = 0; i < board.size(); i++) {
            if (board[i][0] == 'O') {
                dfs(board, i, 0);
            }
            
            if (board[i][board[0].size() - 1] == 'O') {
                dfs(board, i, board[0].size()-1);
            }
        }
    }
    
    void convertSurrondedRegions(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == '-') {
                    board[i][j] = 'O';
                } else if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
        if (!board.size()) return;
        findBorder(board);
        convertSurrondedRegions(board);
    }
};