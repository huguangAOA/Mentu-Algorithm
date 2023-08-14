class Solution {
public:
    int f[105][205], mod_num = (int)(1e9+7);
    int getResult(int p, int d, int r, int n, vector<int> &c) {
        if (f[p][r] != -1) return f[p][r];
        if (p == d) f[p][r] = 1;
        else f[p][r] = 0;
        for (int i = 0; i < n; i++) {
            if (p == i) continue;
            if (abs(c[p] - c[i]) > r) continue;
            f[p][r] += getResult(i, d, r - abs(c[p] - c[i]), n, c);
            f[p][r] %= mod_num;
        }
        return f[p][r];
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        memset(f, -1, sizeof(f));
        return getResult(start, finish, fuel, locations.size(), locations);
    }
};