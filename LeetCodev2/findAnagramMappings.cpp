class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        vector<int> answer;
        unordered_multimap<int,int> hashMap;
        
        if (!A.size() || !B.size() || A.size() != B.size()) return answer;
        
        for (int i = 0; i < B.size(); i++) {
            hashMap.emplace(B[i], i);
        }
        
        for (int i = 0; i < A.size(); i++) {
            int current = A[i];
            auto positionInB = hashMap.find(current);
            answer.push_back(positionInB->second);
            hashMap.erase(positionInB);           
        }
        
        return answer;
    }
};