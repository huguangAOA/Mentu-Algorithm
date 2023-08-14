class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        int dp[105][105][105] = {0}, n = boxes.size();
        for (int l = 1; l <= n; l++) {
            for (int i = 1; i + l - 1 <= n; i++) {
                int j = i + l - 1;
                for (int k = 0; k <= n; k++) {
                    dp[i][j][k] = dp[i][j - 1][0] + (k + 1) * (k + 1);
                    for (int t = i; t < j; t++) {
                        if (boxes[t - 1] != boxes[j - 1]) continue;
                        dp[i][j][k] = max(dp[i][j][k], dp[t + 1][j - 1][0] + dp[i][t][k + 1]);
                    }
                }
            }
        }
        return dp[1][n][0];
    }
};