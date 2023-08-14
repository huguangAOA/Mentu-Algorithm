class Solution {
public:
    int distinctEchoSubstrings(string s) {
        long long base = 31, MOD = (1e9 + 7), h[2005] = {0}, mul[2005] = {0};
        mul[0] = 1;
        for (int i = 1, n = s.size(); i <= n; i++) {
            h[i] = (h[i - 1] * base + s[i - 1]) % MOD;
            mul[i] = mul[i - 1] * base % MOD;
        }
        int ans = 0;
        unordered_set<long long> uniq;
        for (int l = 1, n = s.size(); l * 2 <= n; l++) {
            for (int i = 1; i + 2 * l - 1 <= n; i++) {
                int h1 = (h[i + l - 1] - h[i - 1] * mul[l] % MOD + MOD) % MOD;
                int h2 = (h[i + 2 * l - 1] - h[i + l - 1] * mul[l] % MOD + MOD) % MOD;
                if (uniq.find(h1) != uniq.end() || h1 != h2) continue;
                ans += 1;
                uniq.insert(h1);
            }
        }
        return ans;
    }
};