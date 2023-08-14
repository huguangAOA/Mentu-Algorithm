class Solution {
public:
    int count_prime(int n) {
        int prime[n + 1];
        memset(prime, 0, sizeof(prime));
        prime[0] = prime[1] = 1;
        for (int i = 2; i * i <= n; i++) {
            if (prime[i]) continue;
            for (int j = i * i; j <= n; j += i) prime[j] = 1;
        }
        int cnt = 0;
        for (int i = 2; i <= n; i++) cnt += (prime[i] == 0);
        return cnt;
    }
    long long frac(long long n, long long m) {
        long long ans = 1;
        for (long long i = 2; i <= n; i++) ans = ans * i % m;
        return ans;
    }
    int numPrimeArrangements(int n) {
        int m = count_prime(n), mod_num = 1e9 + 7;
        return frac(m, mod_num) * frac(n - m, mod_num) % mod_num;
    }
};