class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> f[n + 1];
        f[0][0] = 1;
        for (int i = 1, sum = 0; i <= n; i++) {
            int v = nums[i - 1];
            sum += v;
            for (int j = -sum; j <= sum; j++) {
                f[i][j] = f[i - 1][j + v] + f[i - 1][j - v];
            }
        }
        return f[n][target];
    }
};