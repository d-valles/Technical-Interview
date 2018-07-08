class Solution {
public:    
    void recursiveFlood (int row, int col, int newColor, int firstColor, vector<vector<int>>&image) {
        image[row][col] = newColor;
        
        if (row - 1 >= 0 && image[row - 1][col] == firstColor) {
            recursiveFlood(row - 1, col, newColor, firstColor, image);
        }
        
        if (col + 1 < image[0].size() && image[row][col + 1] == firstColor) {
            recursiveFlood(row, col + 1, newColor, firstColor, image);
        }
        
        if (col - 1 >= 0 && image[row][col - 1] == firstColor) {
            recursiveFlood(row, col - 1, newColor, firstColor, image);
        }

        if (row + 1 < image.size() && image[row + 1][col] == firstColor) {
            recursiveFlood(row + 1, col, newColor, firstColor, image);
        }

    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int color = image[sr][sc];
        if (color != newColor) {
            recursiveFlood(sr, sc, newColor, color, image);
        }
        return image;
    }
};