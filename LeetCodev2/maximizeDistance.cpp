class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        vector<int> closestL(seats.size(), INT_MAX);
        vector<int> closestR(seats.size(), INT_MAX);
        int answer = INT_MIN;
        
        for (int i = 0; i < seats.size(); i++) {
            if (seats[i] == 1) {
                closestL[i] = 1;
            } else if(i != 0 && closestL[i - 1] != INT_MAX) {
                closestL[i] = closestL[i - 1] + 1;
            }
        }
        
        for (int i = seats.size() - 1; i >= 0; i--) {
            if (seats[i] == 1) {
                closestR[i] = 1;
            } else if (i != seats.size() - 1 && closestR[i + 1] != INT_MAX) {
                closestR[i] = closestR[i + 1] + 1;
            }
        }
        
        for (int i = 0; i < closestL.size(); i++) {
            int m = min(closestL[i], closestR[i]);
            answer = max(answer, m);
        }
        
        return answer - 1;
    }
};