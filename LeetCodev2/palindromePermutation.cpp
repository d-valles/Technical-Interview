class Solution {
public:
    bool notEven(int number) {
        return number % 2 != 0;
    }
    
    bool validatePalindrome(unordered_map<char,int>&hashMap, bool flag) {
        auto iterator1 = hashMap.begin();
        
        while(iterator1 != hashMap.end()) {
            int current = iterator1->second;
                
            if (!notEven(current)) {
            } else if (notEven(current) && flag) {
                return false;
            } else {
                flag = true;
            }
            iterator1++;
        }
        return true;        
    }
    
    bool canPermutePalindrome(string s) {
        unordered_map<char,int> hashMap;
        for (int i = 0; i < s.size(); i++) {
            auto it = hashMap.find(s[i]);
            if(it != hashMap.end()) {
                hashMap[s[i]]++;
            } else {
                hashMap.emplace(s[i], 1);              
            }
        }

        bool flag = s.size() % 2 == 0;
        return validatePalindrome(hashMap, flag);        
    }
};