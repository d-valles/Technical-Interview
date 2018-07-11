class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        bool hasFindOne = false;
        int perimeter = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    hasFindOne = true;
                }
                
                if (hasFindOne && (i == 0 || grid[i - 1][j] == 0)) {
                    perimeter++;
                }
                
                if (hasFindOne && (j == 0  || grid[i][j - 1] == 0)) {
                    perimeter++;
                }

                if (hasFindOne && (i == grid.size() - 1 || grid[i + 1][j] == 0)) {
                    perimeter++;
                }

                if (hasFindOne && (j == grid[i].size() - 1 || grid[i][j + 1] == 0)) {
                    perimeter++;
                }
                hasFindOne = false;
            }
        }
        return perimeter;
    }
};
