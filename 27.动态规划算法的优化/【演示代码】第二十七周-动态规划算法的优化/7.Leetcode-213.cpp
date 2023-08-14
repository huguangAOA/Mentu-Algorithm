class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        int dp[n + 1][2];
        int ans1, ans2;
        dp[1][0] = 0, dp[1][1] = nums[0];
        for (int i = 2; i <= n; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] + nums[i - 1];
        }
        ans1 = dp[n][0];
        dp[1][0] = 0, dp[1][1] = 0;
        for (int i = 2; i <= n; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] + nums[i - 1];
        }
        ans2 = dp[n][1];
        return max(ans1, ans2);
    }
};