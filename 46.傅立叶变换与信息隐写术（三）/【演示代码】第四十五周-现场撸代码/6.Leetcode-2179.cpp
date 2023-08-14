class FenwickTree {
public :
    FenwickTree(int n) : n(n), c(n + 1) {};
    #define lowbit(x) (x & (-x))
    void add(int i, int x) {
        while (i <= n) c[i] += x, i += lowbit(i);
        return ;
    }
    int query(int i) {
        int sum = 0;
        while (i) sum += c[i], i -= lowbit(i);
        return sum;
    }

private:
    int n;
    vector<int> c;
};
class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        long long n = nums1.size(), ans = 0;
        FenwickTree ind(n);
        unordered_map<int, int> ind_map;
        for (int i = 0; i < n; i++) ind_map[nums2[i]] = i;
        for (int i = 0; i < n; i++) {
            int x = nums1[i], j = ind_map[x];
            int cnti = ind.query(j + 1);
            int green = i - cnti;
            int cntj = n - j - 1 - green;
            ans += 1LL * cnti * cntj;
            ind.add(j + 1, 1);
        }
        return ans;
    }
};