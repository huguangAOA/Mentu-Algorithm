class Solution {
public:
    inline long long val(char c) {
        return c - 'a' + 1;
    }
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        long long base = 1, n = s.size();
        vector<long long> h(n + 1);
        h[n] = 0;
        for (int i = n - 1; i >= 0; --i) h[i] = (h[i + 1] * power + val(s[i])) % modulo;
        for (int i = 0; i < k; i++) base = base * power % modulo;
        for (int i = 0; i + k <= n; i++) {
            if ((h[i] - h[i + k] * base % modulo + modulo) % modulo != hashValue) continue;
            return s.substr(i, k);
        }
        return "error";
    }
};