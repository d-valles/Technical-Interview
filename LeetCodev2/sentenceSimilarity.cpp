class Solution {
public:
    bool compareAll (multimap<string, string>& hashMap, string key, string word) {  
        auto itr1 = hashMap.lower_bound(key);
        auto itr2 = hashMap.upper_bound(key);

        while (itr1 != itr2)    
        {
            if (itr1 -> first == key && itr1->second == word) {
                return true;
            }    
            itr1++;
        }
        return false;
    }
    
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        multimap<string,string> hashMap;
        
        if (words1.size() != words2.size()) return false; 
        if (!words1.size()) return true;
        
        for (int i = 0; i < pairs.size(); i++) {
            pair<string,string> current = pairs[i];
            hashMap.emplace(current.first, current.second);
            hashMap.emplace(current.second, current.first);
        }
        
        for (int i = 0; i < words1.size() && i < words2.size(); i++) {
            
            if (words1[i] == words2[i] || compareAll(hashMap, words1[i], words2[i])) {
                continue;
            } else {
                return false;
            }
        }
        return true;
    }
};