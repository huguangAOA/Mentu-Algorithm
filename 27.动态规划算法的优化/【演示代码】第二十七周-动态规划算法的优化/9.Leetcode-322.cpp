class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int dp[amount + 1];
        for (int i = 0; i <= amount; i++) dp[i] = INT_MAX;
        dp[0] = 0;
        for (auto x : coins) {
            for (int j = x; j <= amount; j++) {
                if (dp[j - x] != INT_MAX) dp[j] = min(dp[j], dp[j - x] + 1);
            }
        }
        if (dp[amount] == INT_MAX) return -1;
        return dp[amount];
    }
};