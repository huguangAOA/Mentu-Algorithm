class Solution {
public:
    int numberOfUniqueGoodSubsequences(string binary) {
        int n = binary.size(), mod_num = (int)(1e9+7);
        int f[n + 1][2], flag = 0;
        f[n][0] = f[n][1] = 0;
        for (int i = n - 1; i >= 0; i--) {
            int j = (binary[i] - '0');
            if (j == 0) flag = 1;
            f[i][j] = f[i + 1][j] + f[i + 1][1 - j] + 1;
            f[i][1 - j] = f[i + 1][1 - j];
            f[i][j] %= mod_num;
            f[i][1 - j] %= mod_num;
        }
        return f[0][1] + flag;
    }
};