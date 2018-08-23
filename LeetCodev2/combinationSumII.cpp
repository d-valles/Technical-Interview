class Solution {
public:
    vector<vector<int>> answer;
    
    void helper(vector<int>& combination, vector<int>& candidates, int target, int position, set<vector<int>>& S) {
        if (target == 0 && S.find(combination) == S.end()) {
            S.emplace(combination);
            answer.push_back(combination);
            return;
        }
        
        for (int i = position; i < candidates.size(); i++) {
            if (target - candidates[i] >= 0) {
                combination.push_back(candidates[i]);
                helper(combination, candidates, target - candidates[i], i + 1, S);
                combination.pop_back();
            }   
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> combination;   
        sort(candidates.begin(), candidates.end());
        set<vector<int>> S;
        
        helper(combination, candidates, target, 0, S);
        return answer;
    }
};