class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(!grid.size()) return 0;
        
        int m = grid.size();
        int n = grid[0].size();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int minP = 0; 
               
                if (i != 0 && j != 0) {
                   minP = min(grid[i - 1][j], grid[i][j - 1]);
                } else if(i != 0) {
                   minP = grid[i - 1][j];
                } else if (j != 0) {
                   minP = grid[i][j - 1];
                }
                
                grid[i][j] += minP;
            }
        }
        
        return grid[m-1][n-1];
    }
};