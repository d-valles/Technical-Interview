class Solution {
public:
    string removeKdigits(string num, int k) {
        if (num.size() < k) return "0";
        string ans = "";
        
        for (int i = 0; i < num.size(); i++) {
            char c = num[i];
            while(ans.length() && ans.back() > c && k) {
                ans.pop_back();
                k--;
            }
            
            if (ans.length() || c != '0') {
                ans.push_back(c);
            }
        }
        
        while(ans.length() && k) {
            ans.pop_back();
            k--;
        }
        
        return ans.empty() ? "0" : ans;
    }
};