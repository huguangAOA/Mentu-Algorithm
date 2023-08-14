class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size(), offset = 0;
        for (auto x : nums) offset += x;
        offset += 2000;
        int f[n + 1][offset * 2 + 2000];
        memset(f, 0, sizeof(f));
        f[0][offset] = 1;
        for (int i = 1, sum = 0; i <= n; i++) {
            int v = nums[i - 1];
            sum += v;
            for (int j = -sum; j <= sum; j++) {
                f[i][j + offset] = f[i - 1][j + v + offset] + f[i - 1][j - v + offset];
            }
        }
        return f[n][target + offset];
    }
};