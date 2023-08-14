class Solution {
public:
    void getCount01(string &s, int &n, int &m) {
        for (auto x : s) x == '0' ? (++n) : (++m);
        return ;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int dp[strs.size() + 1][m + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 1, I = strs.size(); i <= I; i++) {
            int cnt0 = 0, cnt1 = 0;
            getCount01(strs[i - 1], cnt0, cnt1);
            for (int j = 0; j <= m; j++) {
                for (int k = 0; k <= n; k++) {
                    dp[i][j][k] = dp[i - 1][j][k];
                    if (j < cnt0) continue;
                    if (k < cnt1) continue;
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - cnt0][k - cnt1] + 1);
                }
            }
        }
        return dp[strs.size()][m][n];
    }
};