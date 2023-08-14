class Solution {
public:
    int countPrimes(int n) {
        int *prime = new int[n + 1];
        for (int i = 0; i < n; i++) prime[i] = 0;
        for (int i = 2; i * i < n; i++) {
            if (prime[i]) continue;
            for (int j = 2 * i; j < n; j += i) {
                prime[j] = 1;
            }
        }
        int cnt = 0;
        for (int i = 2; i < n; i++) cnt += (prime[i] == 0);
        delete[] prime;
        return cnt;
    }
};