class Solution {
public:
    long long dis2(int i, int j, vector<vector<int>> &bombs) {
        #define D(x) (1LL * (x) * (x))
        return D(bombs[i][0] - bombs[j][0]) + D(bombs[i][1] - bombs[j][1]);
        #undef D
    }
    void init_g(vector<vector<int>> &bombs, vector<vector<int>> &g, int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (dis2(i, j, bombs) > 1LL * bombs[i][2] * bombs[i][2]) continue; 
                g[i].push_back(j);
            }
        }
        return ;
    }
    int dfs(int i, vector<vector<int>> &g, vector<int>& vis) {
        vis[i] = 1;
        int ans = 1;
        for (auto x : g[i]) {
            if (vis[x] == 0) ans += dfs(x, g, vis);
        }
        return ans;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> g(n);
        init_g(bombs, g, n);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            vector<int> vis(n, 0);
            ans = max(ans, dfs(i, g, vis));
        }
        return ans;
    }
};