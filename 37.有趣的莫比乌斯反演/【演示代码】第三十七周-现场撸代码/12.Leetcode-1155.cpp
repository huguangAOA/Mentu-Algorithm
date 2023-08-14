class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        int dp[d + 1][target + 1], mod_num = 1e9 + 7;
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 1; i <= d; i++) {
            for (int j = i; j <= target; j++) {
                for (int k = 1; k <= f; k++) {
                    if (j < k) break;
                    dp[i][j] += dp[i - 1][j - k];
                    dp[i][j] %= mod_num;
                }
            }
        }
        return dp[d][target];
    }
};