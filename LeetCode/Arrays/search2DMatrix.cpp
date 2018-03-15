/*
    You can modify this method to use one binary search by treating the matrix as a long list.
*/
class Solution {
public:
    bool binarySearchRow(vector<int> &row, int left, int right, int target) {
        if(row.size() == 0) return false;
        
        while(left <= right) {
            int mid = (right + left) / 2;
            
            if (row[mid] == target) {
                return true;
            }
            else if (row[mid] > target) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        
        return false;
    }
    
    bool searchColumn(vector<vector<int>>&matrix, int target) {
        if(!matrix.size() || !matrix[0].size()) return false;
        
        int bottom = 0;
        int top = matrix.size() - 1;
        
        while(bottom <= top) {

            int mid = (top + bottom) / 2;
            
            if (matrix[mid][0] <= target && matrix[mid][matrix[mid].size() - 1] >= target) {
                return binarySearchRow(matrix[mid], 0, matrix[mid].size() - 1, target);
            }
            else if (matrix[mid][matrix[mid].size() - 1] < target) {
                bottom = mid + 1;
            }
            else {
                top = mid - 1;
            }
            
        }
        
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return searchColumn(matrix, target);
    }
};