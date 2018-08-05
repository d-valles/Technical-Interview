class Solution {
public:
    void getMinOption(vector<vector<int>>& triangle, int i, int j) {
        int op1 = triangle[i + 1][j];
        int op2 = triangle[i + 1][j + 1];
        
        triangle[i][j] += min(op1, op2);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i = triangle.size() - 2; i >= 0; i--) {
            for (int j = 0; j < triangle[i].size(); j++) {
                getMinOption(triangle, i, j);
            }
        }
        
        return triangle[0][0];
    }
};