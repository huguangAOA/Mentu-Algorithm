class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        vector<int> indeg(n, 0);
        vector<set<int>> ans(n);
        for (auto x : edges) {
            g[x[0]].push_back(x[1]);
            indeg[x[1]] += 1;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) if (indeg[i] == 0) q.push(i);
        while (!q.empty()) {
            int ind = q.front();
            for (auto x : g[ind]) {
                for (auto y : ans[ind]) ans[x].insert(y);
                ans[x].insert(ind);
                indeg[x] -= 1;
                if (indeg[x] == 0) q.push(x);
            }
            q.pop();
        }
        vector<vector<int>> ret(n);
        for (int i = 0; i < n; i++) {
            for (auto x : ans[i]) ret[i].push_back(x);
        }
        return ret;
    }
};