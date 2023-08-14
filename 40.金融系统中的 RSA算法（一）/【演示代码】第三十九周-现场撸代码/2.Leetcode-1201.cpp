class Solution {
public:
    struct CHECKER {
        CHECKER(long long a, long long b, long long c) 
        : a(a), b(b), c(c), 
          ab(lcm(a, b)), ac(lcm(a, c)), bc(lcm(b, c)),
          abc(lcm(lcm(a, b), c)) {}
        long long a, b, c, ab, bc, ac, abc;
        long long gcd(long long a, long long b) {
            if (b) return gcd(b, a % b);
            return a;
        }
        long long lcm(long long a, long long b) {
            return a * b / gcd(a, b);
        }
        long long get(long long x) {
            return x / a + x / b + x / c - x / ab - x / bc - x / ac + x / abc;
        }
    };
    int nthUglyNumber(int n, int a, int b, int c) {
        CHECKER check(a, b, c);
        long long head = 1, tail = n * min(a, min(b, c)), mid;
        while (head < tail) {
            mid = (head + tail) >> 1;
            if (check.get(mid) < n) head = mid + 1;
            else tail = mid;
        }
        return head;
    }
};