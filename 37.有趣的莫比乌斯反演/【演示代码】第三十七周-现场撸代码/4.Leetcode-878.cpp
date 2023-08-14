class Solution {
public:
    long long gcd(long long a, long long b) {
        if (b) return gcd(b, a % b);
        return a;
    }
    long long lcm(long long a, long long b) {
        return a * b / gcd(a, b);
    }
    long long f(long long n, long long a, long long b) {
        return n / a + n / b - n / lcm(a, b);
    }
    int nthMagicalNumber(int n, int a, int b) {
        long long l = 1, r = (long long)n * (long long)min(a, b), mid, mod_num = 1e9 + 7;
        while (l < r) {
            mid = (l + r) >> 1;
            if (f(mid, a, b) < n) l = mid + 1;
            else r = mid;
        }
        return l % mod_num;
    }
};