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
class NumArray {
public:
    FenwickTree tree;
    NumArray(vector<int>& nums) : tree(nums.size()) {
        for (int i = 0; i < nums.size(); i++) {
            tree.add(i + 1, nums[i]);
        }
        return ;
    }
    
    void update(int index, int val) {
        tree.add(index + 1, val - tree.at(index + 1));
        return ;
    }
    
    int sumRange(int left, int right) {
        return tree.query(right + 1) - tree.query(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */