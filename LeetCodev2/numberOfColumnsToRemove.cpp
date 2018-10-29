int needsToBeRemoved(vector<vector<char>> &matrix, int index) {
    char prev = '*'
    for (int i = 0; i < matrix.size(); i++) {
        char current = matrix[i][index]l
        if (prev == *) {
            continue;
        } else if (prev > current) {
            return 1;
        }       
        prev = current;
    }

    return 0;
}

int numberOfColumnsToRemove(vector<vector<char>> &matrix) {
    int columnsToRemove = 0;
    if (matrix.size() == 0) return columnsToRemove;

    for (int i = 0; i < matrix[0].size(); i++) {
        columnsToRemove += needsToBeRemoved(matrix, i);
    }

    return columnsToRemove;
}