class Solution {
public:
    struct Data {
        Data(int i = 0, int j = 0)
        : i(i), j(j) {}
        int i, j;
    };
    int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
    int movingCount(int m, int n, int k) {
        vector<int> dsum(100);
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                dsum[i * 10 + j] = i + j;
            }
        }
        queue<Data> q;
        unordered_set<int> h;
        h.insert(0);
        q.push(Data(0, 0));
        int ans = 0;
        while (!q.empty()) {
            Data cur = q.front();
            ans += 1;
            for (int i = 0; i < 4; i++) {
                int x = cur.i + dir[i][0];
                int y = cur.j + dir[i][1];
                if (x < 0 || x >= m) continue;
                if (y < 0 || y >= n) continue;
                if (h.find(x * n + y) != h.end()) continue;
                if (dsum[x] + dsum[y] > k) continue;
                h.insert(x * n + y);
                q.push(Data(x, y));
            }
            q.pop();
        }
        return ans;
    }
};