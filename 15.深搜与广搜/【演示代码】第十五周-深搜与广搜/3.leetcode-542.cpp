class Solution {
public:
    struct Data {
        Data(int i = 0, int j = 0, int k = 0)
        : i(i), j(j), k(k) {}
        int i, j, k;
    };
    void init_queue(
        queue<Data> &q, vector<vector<int>> &vis, 
        int n, int m, vector<vector<int>> &mat
    ) {
        for (int i = 0; i < n; i++) {
            vis.push_back(vector<int>());
            for (int j = 0; j < m; j++) {
                vis[i].push_back(-1);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j]) continue;
                vis[i][j] = 0;
                q.push(Data(i, j, 0));
            }
        }
        return ;
    }
    int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        queue<Data> q;
        vector<vector<int>> vis;
        init_queue(q, vis, n, m, mat);
        while (!q.empty()) {
            Data cur = q.front();
            for (int k = 0; k < 4; k++) {
                int x = cur.i + dir[k][0];
                int y = cur.j + dir[k][1];
                if (x < 0 || x >= n) continue;
                if (y < 0 || y >= m) continue;
                if (vis[x][y] != -1) continue;
                vis[x][y] = cur.k + 1;
                q.push(Data(x, y, cur.k + 1));
            }
            q.pop();
        }
        return vis;
    }
};