class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(!prices.size()) return 0;
        
        int minValue = prices[0];
        int mProfit = 0;
        
        for (int i = 0; i < prices.size(); i++) {
            minValue = min(minValue, prices[i]);
            mProfit = max(mProfit, prices[i] - minValue);
        }
        
        return mProfit;
    }
};