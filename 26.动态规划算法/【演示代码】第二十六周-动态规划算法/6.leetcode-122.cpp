class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum = 0;
        for (int i = 1; i < prices.size(); i++) {
            int delta = prices[i] - prices[i - 1];
            if (delta > 0) sum += delta;
        }
        return sum;
    }
};