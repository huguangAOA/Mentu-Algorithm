class Solution {
public:
    int power(int a, int b, int c) {
        int base = a % c, ans = 1;
        while (b) {
            if (b & 1) ans = ans * base % c;
            base = base * base % c; 
            b >>= 1;
        }
        return ans;
    }
    int superPow(int a, vector<int>& b) {
        int base = a, ans = 1, mod_num = 1337;
        for (int i = b.size() - 1; i >= 0; --i) {
            ans = ans * power(base, b[i], mod_num) % mod_num;
            base = power(base, 10, mod_num);
        }
        return ans;
    }
};