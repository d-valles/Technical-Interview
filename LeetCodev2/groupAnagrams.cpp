class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> H;
        vector<vector<string>> answer;
        for (int i = 0; i < strs.size(); i++) {
            string current = strs[i];
            sort(current.begin(), current.end());
            H[current].push_back(strs[i]);
        }
        
        for (auto it = H.begin(); it != H.end(); it++) {
            answer.push_back(it->second);
        }
        
        return answer;
    }
};