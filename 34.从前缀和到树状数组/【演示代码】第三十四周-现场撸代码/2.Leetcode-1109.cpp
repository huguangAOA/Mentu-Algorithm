#define lowbit(x) (x & (-x))
class FenwickTree {
public :
    FenwickTree(int size) : n(size), c(n + 1) {}
    void add(int i, int x) {
        while (i <= n) c[i] += x, i += lowbit(i);
        return ;
    }
    int at(int ind) { return query(ind) - query(ind - 1); }
    int query(int x) {
        int sum = 0;
        while (x) sum += c[x], x -= lowbit(x);
        return sum;
    }
    void output() {
        int len = 0;
        for (int i = 1; i <= n; i++) {
            len += printf("%5d", i);
        }
        printf("\n");
        for (int i = 0; i < len + 6; i++) {
            printf("=");
        }
        printf("\n");
        for (int i = 1; i <= n; i++) {
            printf("%5d", c[i]);
        }
        printf("\n");
        for (int i = 1; i <= n; i++) {
            printf("%5d", query(i) - query(i - 1));
        }
        printf("\n\n\n");
        return ;
    }

private:
    int n; // 下标上限
    vector<int> c;
};
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        FenwickTree tree(n);
        for (auto x : bookings) {
            tree.add(x[0], x[2]);
            tree.add(x[1] + 1, -x[2]);
        }
        vector<int> ret(n);
        for (int i = 1; i <= n; i++) {
            ret[i - 1] = tree.query(i);
        }
        return ret;
    }
};