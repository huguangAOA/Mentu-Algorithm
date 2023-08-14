class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int dp[n][2];
        dp[0][0] = dp[0][1] = nums[0]; // step1
        int ans = dp[0][0];
        for (int i = 1; i < n; i++) {
            int val1 = dp[i - 1][0] * nums[i];
            int val2 = dp[i - 1][1] * nums[i];
            int val3 = nums[i];
            dp[i][0] = max(val1, max(val2, val3));
            dp[i][1] = min(val1, min(val2, val3));
            ans = max(dp[i][0], ans);
        }
        return ans;
    }
};