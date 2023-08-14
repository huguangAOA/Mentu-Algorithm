class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int dp[n][n];
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                dp[i][j] = INT_MAX;
                if (j <= i - 1) dp[i][j] = min(dp[i][j], dp[i - 1][j] + triangle[i][j]);
                if (j > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + triangle[i][j]);
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            ans = min(ans, dp[n - 1][i]);
        }
        return ans;
    }
};