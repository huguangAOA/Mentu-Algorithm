class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        vector<vector<int>> g(n, vector<int>(n, 0));
        vector<int> like(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1; j++) {
                g[i][preferences[i][j]] = j;
            }
        }
        for (auto x : pairs) {
            like[x[0]] = g[x[0]][x[1]];
            like[x[1]] = g[x[1]][x[0]];
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0, J = like[i]; j < J; j++) {
                int t = preferences[i][j];
                if (g[t][i] >= like[t]) continue;
                ans += 1;
                break;
            }
        }
        return ans;
    }
};