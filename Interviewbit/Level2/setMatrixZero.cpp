void firstPassCheck(vector<vector<int>> &A, int y, int x) {
    for (int i = y; i < A.size(); i++) {
        if (A[i][x] == 1) {
            A[i][x] = -1;
        }
    }
    
    for (int i = y; i >= 0; i--) {
        if (A[i][x] == 1) {
            A[i][x] = -1;
        }
    }
    
    for (int i = x; i < A[y].size(); i++) {
        if (A[y][i] == 1) {
            A[y][i] = -1;
        }       
    }
    
    for (int i = x; i >= 0; i--) {
        if (A[y][i] == 1) {
            A[y][i] = -1;
        }        
    }
}

void convert(vector <vector<int>> &A) {
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A[i].size(); j++) {
            if (A[i][j] == -1) {
                A[i][j] = 0;
            }
        }   
    } 
}

void Solution::setZeroes(vector<vector<int> > &A) {
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A[i].size(); j++) {
            if (A[i][j] == 0) {
                firstPassCheck(A, i, j);
            }
        }   
    }
    
    convert(A);
}