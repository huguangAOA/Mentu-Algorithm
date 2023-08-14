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
    vector<int> processQueries(vector<int>& queries, int m) {
        int lenq = queries.size();
        FenwickTree tree(lenq + m);
        vector<int> pos(m + 1);
        for (int i = 1; i <= m; i++) {
            tree.add(lenq + i, 1);
            pos[i] = lenq + i;
        }
        vector<int> ret(lenq);
        for (int i = 0; i < lenq; i++) {
            int ind = pos[queries[i]];
            ret[i] = tree.query(ind) - 1;
            tree.add(ind, -1);
            pos[queries[i]] = lenq - i;
            tree.add(lenq - i, 1);
        }
        return ret;
    }
};