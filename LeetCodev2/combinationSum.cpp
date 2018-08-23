class Solution {
public:
    vector<vector<int>> answer;
    
    void helper(vector<int>& combination, vector<int>& candidates, int target, int position) {
        if (target == 0) {
            answer.push_back(combination);
            return;
        }
        
        for (int i = position; i < candidates.size(); i++) {
            if (candidates[i] > target) return;
            combination.push_back(candidates[i]);
            helper(combination, candidates, target - candidates[i], i);
            combination.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> combination;   
        sort(candidates.begin(), candidates.end());
        
        helper(combination, candidates, target, 0);
        return answer;
    }
};