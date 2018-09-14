class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> S;
        int len = temperatures.size();
        vector<int> answer(len, 0);
        
        S.push({temperatures[len - 1], len - 1});
        
        for (int i = len - 1; i >= 0; i--) {
            while (!S.empty() && temperatures[i] >= S.top().first) {
                S.pop();
            }
            
            if (!S.empty()) {
                answer[i] = S.top().second - i;
            }
            
            S.push({temperatures[i], i});
        }
        
        return answer;
    }
};