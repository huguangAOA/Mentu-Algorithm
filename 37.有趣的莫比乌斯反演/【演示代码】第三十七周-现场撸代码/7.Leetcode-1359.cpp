class Solution {
public:
    int countOrders(int n) {
        long long ans = 1, mod_num = 1e9 + 7;
        for (int i = 2; i <= n; i++) {
            ans = ans * (2 * i * i - i) % mod_num;
        }
        return ans;
    }
};