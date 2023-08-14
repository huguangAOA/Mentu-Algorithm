class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                dp[i][j] = dp[i - 1][j];
                int x = 0, y = 0;
                for (auto t : piles[i - 1]) {
                    x += 1, y += t;
                    if (x > j) break;
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - x] + y);
                }
            }
        }
        return dp[n][k];
    }
};