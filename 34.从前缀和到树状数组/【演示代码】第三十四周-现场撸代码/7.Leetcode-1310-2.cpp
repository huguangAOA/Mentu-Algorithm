#define lowbit(x) (x & (-x))
class FenwickTree {
public :
    FenwickTree(int size) : n(size), c(n + 1) {}
    void add(int i, int x) {
        while (i <= n) c[i] ^= x, i += lowbit(i);
        return ;
    }
    int at(int ind) { return query(ind) ^ query(ind - 1); }
    int query(int x) {
        int sum = 0;
        while (x) sum ^= c[x], x -= lowbit(x);
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
            printf("%5d", at(i));
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
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        FenwickTree tree(n);
        for (int i = 0; i < n; i++) {
            tree.add(i + 1, arr[i]);
        }
        vector<int> ret;
        for (auto x : queries) {
            ret.push_back(tree.query(x[1] + 1) ^ tree.query(x[0]));
        }
        return ret;
    }
};