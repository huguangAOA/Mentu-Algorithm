class Solution {
public:
    unordered_map<int, bool> h;
    bool dfs(int mask, int n, int total) {
        if (h.find(mask) != h.end()) return h[mask];
        for (int i = 1; i <= n; i++) {
            if (mask & (1 << i)) continue;
            if (i >= total || !dfs(mask | (1 << i), n,  total - i)) {
                return h[mask] = true;
            }
        }
        return h[mask] = false;
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int n = maxChoosableInteger, mask = 0;
        if ((1 + n) * n / 2 < desiredTotal) return false;
        h.clear();
        return dfs(mask, maxChoosableInteger, desiredTotal);
    }
};