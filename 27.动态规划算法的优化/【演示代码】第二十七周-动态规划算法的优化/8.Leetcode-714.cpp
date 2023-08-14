class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int dp[n][2];
        dp[0][0] = 0, dp[0][1] = - fee - prices[0];
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - fee - prices[i]);
        }
        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};