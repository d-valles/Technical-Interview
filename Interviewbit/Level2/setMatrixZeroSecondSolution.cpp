bool hasZeroFirstColumn (vector<vector<int>> &A) {
    for (int i = 0; i < A.size(); i++) {
        if (A[i][0] == 0) return true;
    }
    return false;   
}

bool hasZeroFirstRow (vector<vector<int>> &A) {
    for (int i = 0; i < A[0].size(); i++) {
        if (A[0][i] == 0) return true;
    }
    return false;
}

void convertZeroes (vector<vector<int>>& A) {
    for (int i = 1; i < A.size(); i++) {
        for (int j = 1; j < A[i].size(); j++) {
            if (A[i][0] == 0 || A[0][j] == 0)  A[i][j] = 0;
        }
    }
}


void convertFirstRow (vector<vector<int>>& A) {
    for (int i = 0; i < A[0].size(); i++) {
        A[0][i] = 0;
    }
}

void convertFirstCol (vector<vector<int>>& A) {
    for (int i = 0; i < A.size(); i++) {
        A[i][0] = 0;
    }    
}

void Solution::setZeroes(vector<vector<int>>& A) {
    if (!A.size()) return;
    if (!A[0].size()) return;
    
    bool row = hasZeroFirstRow(A);
    bool col = hasZeroFirstColumn(A);
    
    for (int i = 1; i < A.size(); i++) {
        for (int j = 1; j < A[i].size(); j++) {
            if (A[i][j] == 0) {
                A[i][0] = 0;
                A[0][j] = 0;
            }
        }
    }
    convertZeroes(A);
    
    if (row) convertFirstRow(A);
    if (col) convertFirstCol(A);
}