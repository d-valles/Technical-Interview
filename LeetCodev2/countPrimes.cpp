class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        vector<int> passed(n, false);
        
        for (int i = 2; i <= sqrt(n); i++) {
            if (!passed[i]) {
                for (int j = i + i; j < n; j += i) {
                    passed[j] = true;
                }     
            }     
        }
        
        for (int i = 2; i < passed.size(); i ++) {
            if (!passed[i]) count++;
        }

        return count;
    }
};