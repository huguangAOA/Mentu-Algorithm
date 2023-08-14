class Solution {
public:
    int pick(int n, int mark[]) {
        int i = 0, cnt = 0;
        do {
            i += 1;
            cnt += (mark[i] == 0);
        } while (cnt < n);
        mark[i] = 1;
        return i;
    }
    string getPermutation(int n, int k) {
        int base = 1, mark[n + 1];
        memset(mark, 0, sizeof(mark));
        for (int i = 1; i < n; i++) base *= i;
        stringstream ss;
        for (int i = n; i >= 1; --i) {
            int ind = 1 + (k - 1) / base;
            ss << pick(ind, mark);
            k -= (ind - 1) * base;
            if (i > 1) base /= (i - 1);
        }
        return ss.str();
    }
};