class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size(), offset = 0;
        for (auto x : nums) offset += x;
        offset += 2000;
        int __f[n + 1][offset * 2 + 2000], *f[n + 1];
        memset(__f, 0, sizeof(__f));
        for (int i = 0; i <= n; i++) f[i] = __f[i] + offset;
        
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