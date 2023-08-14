class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int cnt[10005] = {0}, dp[10005] = {0};
        for (auto x : nums) cnt[x] += 1;
        dp[1] = cnt[1];
        for (int i = 2; i <= 10000; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + i * cnt[i]);
        }
        return dp[10000];
    }
};