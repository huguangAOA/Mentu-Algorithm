class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        vector<vector<int>> g(n + 1, vector<int>(n + 1, 0));
        // 01
        for (auto x : dig) g[x[0] + 1][x[1] + 1] = 1;
        
        // 012345678
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                g[i][j] += g[i][j - 1] + g[i - 1][j] - g[i - 1][j - 1];
            }
        }

        int ans = 0;
        for (auto x : artifacts) {
            int a1 = x[0] + 1, a2 = x[1] + 1, b1 = x[2] + 1, b2 = x[3] + 1;
            int l = b1 - a1 + 1, w = b2 - a2 + 1;
            int cnt = g[b1][b2] - g[a1 - 1][b2] - g[b1][a2 - 1] + g[a1 - 1][a2 - 1];
            if (l * w == cnt) ans += 1;
        }
        return ans;
    }
};