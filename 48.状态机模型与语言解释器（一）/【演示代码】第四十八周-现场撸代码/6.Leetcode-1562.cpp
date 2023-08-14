class UnionSet {
public :
    UnionSet(int n) : fa(n + 1), size(n + 1), cnt(n + 2, 0) {
        for (int i = 0; i <= n; i++) {
            fa[i] = i;
            size[i] = 1;
        }
        cnt[1] = n + 1;
        return ;
    }
    int get(int x) {
        if (fa[x] == x) return x;
        return (fa[x] = get(fa[x]));
    }
    void merge(int a, int b) {
        int aa = get(a), bb = get(b);
        if (aa == bb) return ;
        fa[aa] = bb;
        cnt[size[bb]] -= 1;
        cnt[size[aa]] -= 1;
        size[bb] += size[aa];
        cnt[size[bb]] += 1;
        return ;
    }
    vector<int> fa, size, cnt;
};

class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size(), ans = -1;
        UnionSet u(n);
        for (int i = 0; i < n; i++) {
            u.merge(arr[i], arr[i] - 1);
            if (u.cnt[m + 1]) ans = i + 1;
        }
        return ans;
    }
};