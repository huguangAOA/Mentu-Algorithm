class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size(), m = amount;
        int dp[n][m + 1];
        memset(dp, -1, sizeof(dp));
        for (int i = 0, j = 0; i <= m; i += coins[0], j++) dp[0][i] = j;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= m; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j < coins[i] || dp[i][j - coins[i]] == -1) continue;
                if (dp[i][j] == -1 || dp[i][j - coins[i]] + 1 < dp[i][j]) {
                    dp[i][j] = dp[i][j - coins[i]] + 1;
                }
            }
        }
        return dp[n - 1][m];
    }
};