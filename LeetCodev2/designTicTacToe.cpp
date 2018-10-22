class TicTacToe {
public:
    vector<vector<int>> Table;
    int length;
    
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        Table =  vector<vector<int>>(n, vector<int>(n, 0));
        length = n;
    }
    
    bool checkDiagonal(int player, int row, int col) {
        int i = 0;
        int j = 0;
        int len = length;
        int count = 0;
        
        while (i < len && j < len) {
            if (Table[i++][j++] == player) {
                count++;
            }
        }
        
        if (count == len) return true;
        
        i = len - 1;
        j = 0;
        while (i >= 0 && j < len) {
            cout<<Table[i][j]<<" ";
            if (Table[i--][j++] != player) {
                return false;
            }
        }
            
        return true;
    }
    
    bool checkHorizontal(int player, int y) {
        for (int i = 0; i < length; i++) {
            if (Table[y][i] != player) return false;
        }
        return true;
    }
    
    bool checkVertical(int player, int x) {
        for (int i = 0; i < length; i++) {
            if (Table[i][x] != player) return false;
        }
        return true;
    }
    
    bool check(int row, int col, int player) {
        return checkDiagonal(player, row, col) || checkHorizontal(player, row) || checkVertical(player, col);
    }
    
    void insert (int row, int col, int player) {
        Table[row][col] = player;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        if (Table[row][col] != 0) return 0;
        insert(row, col, player);
        if (check(row, col, player)) return player;
        return 0;
    }
};