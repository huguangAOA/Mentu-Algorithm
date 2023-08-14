class Solution {
public:
    int getmid(int a, int b, int c) {
        if(a > b) swap(a, b);
        if(a > c) swap(a, c);
        if(b > c) swap(b, c);
        return b;
    }
    void quick_select(vector<int> &arr, int l, int r, int k) {
        if(l >= r) return ;
        int x = l, y = r, mid = getmid(arr[l], arr[(l + r) / 2], arr[r]);
        do {
            while(arr[x] < mid) x++;
            while(arr[y] > mid) y--;
            if(x <= y) {
                swap(arr[x], arr[y]);
                x++, y--;
            }
        } while(x <= y);
        if(y - l == k - 1) return ; // 左区间数量等于k, 直接返回
        if(y - l >= k) { // 左区间数量大于k, 继续扩大
            quick_select(arr, l, y, k);
        } else {
            quick_select(arr, x, r, k - x + l);
        }
        return ;
    }

    vector<int> smallestK(vector<int>& arr, int k) {
        vector<int> ans;
        if(k == 0) return ans;
        quick_select(arr, 0, arr.size() - 1, k);
        while(k) ans.push_back(arr[--k]);
        return ans;
    }
};