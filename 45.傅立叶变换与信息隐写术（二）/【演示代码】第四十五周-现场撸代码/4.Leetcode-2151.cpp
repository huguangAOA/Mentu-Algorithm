class Solution {
public:
    int countOne(int x) {
        int cnt = 0;
        while (x) {
            x &= (x - 1);
            cnt += 1;
        }
        return cnt;
    }
    bool check(vector<vector<int>>& g, int mark, int n) {
        for (int i = 0; i < n; i++) {
            if ((mark & (1 << i)) == 0) continue;
            for (int j = 0; j < n; j++) {
                if (g[i][j] == 2) continue;
                if (g[i][j] != !!(mark & (1 << j))) return false;
            }
        }
        return true;
    }
    int maximumGood(vector<vector<int>>& statements) {
        int n = statements.size(), ans = 0;
        for (int i = 0, I = (1 << n); i < I; i++) {
            if (check(statements, i, n) == false) continue;
            ans = max(ans, countOne(i));
        }
        return ans;
    }
};