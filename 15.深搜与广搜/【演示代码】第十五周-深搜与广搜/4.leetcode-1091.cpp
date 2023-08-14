class Solution {
public:
    struct Data {
        Data(int i = 0, int j = 0, int l = 0)
        : i(i), j(j), l(l) {}
        int i, j, l;
    };
    int dir[8][2] = {
        0, 1, 1, 0, 0, -1, -1, 0,
        1, -1, -1, 1, 1, 1, -1, -1
    };
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> vis;
        for (int i = 0; i < n; i++) {
            vis.push_back(vector<int>(n));
        }
        queue<Data> q;
        if (grid[0][0]) return -1;
        vis[0][0] = 1;
        q.push(Data(0, 0, 1));
        while (!q.empty()) {
            Data cur = q.front();
            if (cur.i == n - 1 && cur.j == n - 1) return cur.l;
            for (int k = 0; k < 8; k++) {
                int x = cur.i + dir[k][0];
                int y = cur.j + dir[k][1];
                if (x < 0 || x >= n) continue;
                if (y < 0 || y >= n) continue;
                if (grid[x][y]) continue;
                if (vis[x][y]) continue;
                vis[x][y] = 1;
                q.push(Data(x, y, cur.l + 1));
            }
            q.pop();
        }
        return -1;
    }
};