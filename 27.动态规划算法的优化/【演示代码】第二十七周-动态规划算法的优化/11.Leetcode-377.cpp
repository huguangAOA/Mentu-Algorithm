class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        unsigned int f[target + 1];
        f[0] = 1;
        for (int j = 1; j <= target; j++) {
            f[j] = 0;
            for (auto x : nums) {
                if (j < x) continue;
                f[j] += f[j - x];
            }
        }
        return f[target];
    }
};