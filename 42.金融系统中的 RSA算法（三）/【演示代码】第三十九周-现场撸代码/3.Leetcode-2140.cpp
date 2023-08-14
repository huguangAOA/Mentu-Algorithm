class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        long long n = questions.size(), dp[n + 1];
        dp[n] = 0;
        for (long long i = n - 1; i >= 0; --i) {
            dp[i] = max(dp[i + 1], dp[min(i + questions[i][1] + 1, n)] + questions[i][0]);
        }
        return dp[0];
    }
};