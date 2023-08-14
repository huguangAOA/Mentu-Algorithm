class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int f[amount + 1];
        memset(f, 0, sizeof(f));
        f[0] = 1;
        for (auto x : coins) {
            for (int j = x; j <= amount; j++) {
                f[j] += f[j - x];
            }
        }
        return f[amount];
    }
};