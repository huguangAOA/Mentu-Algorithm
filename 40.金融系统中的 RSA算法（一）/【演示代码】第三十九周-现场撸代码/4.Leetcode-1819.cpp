class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        int g[200005] = {0}, max_n = 0;
        for (auto x : nums) {
            max_n = max(max_n, x);
            g[x] = x;
        }
        int cnt = 0;
        for (int i = 1; i <= max_n; i++) {
            int ans = -1;
            for (int j = i; j <= max_n; j += i) {
                if (g[j] == 0) continue;
                if (ans == -1) ans = j;
                else ans = gcd(ans, j);
            }
            if (ans == i) cnt += 1;
        }
        return cnt;
    }
};