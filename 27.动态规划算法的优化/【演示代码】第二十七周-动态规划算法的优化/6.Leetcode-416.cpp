class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto x : nums) sum += x;
        if (sum % 2) return false;
        sum /= 2;
        int f[sum + 1];
        memset(f, 0, sizeof(f));
        f[0] = 1;
        for (auto x : nums) {
            for (int i = sum; i >= x; i--) {
                f[i] |= f[i - x];
            }
            if (f[sum]) break;
        }
        return f[sum];
    }
};