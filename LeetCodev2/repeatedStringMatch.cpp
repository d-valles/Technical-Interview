class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int iterations = 1;
        string newA = A;
        while(newA.length() < B.length()) {
            newA.append(A);
            iterations++;
        }
        if (newA.find(B) != -1) return iterations;
        newA.append(A);
        if (newA.find(B) != -1) return iterations + 1;
        return -1;
    }
};