/*
Input:
11110
11010
11000
00000
*/
class Solution {
public:
    bool isValid(int i, int j, int leni, int lenj) {
        if (i < 0 || i > leni) return false;
        if (j < 0 || j > lenj) return false;
        return true;
    }

    void dfs(vector<vector<char>>& grid, int i, int j) {
        grid[i][j] = '.';

        int leni = grid.size() - 1;
        int lenj = grid[i].size() - 1;

        if(isValid(i + 1, j, leni, lenj) && grid[i+1][j] == '1') {
            dfs(grid, i + 1, j);
        }
        if(isValid(i - 1, j, leni, lenj) && grid[i-1][j] == '1') {
            dfs(grid, i - 1, j);
        }
        if(isValid(i, j, leni, lenj) && grid[i][j+1] == '1') {
            dfs(grid, i, j + 1);
        }
        if(isValid(i, j, leni, lenj) && grid[i][j-1] == '1') {
            dfs(grid, i, j - 1);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int totalNumIslands = 0;
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    totalNumIslands++;
                }
            }
        }

        return totalNumIslands;
    }
};