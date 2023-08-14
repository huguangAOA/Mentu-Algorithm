class Solution {
public:

    const int threshold = 16;
    inline int median(int a, int b, int c) {
        if(a > b) swap(a, b);
        if(a > c) swap(a, c);
        if(b > c) swap(b, c);
        return b;
    }

    void __quick_sort_v3(vector<int>& arr, int l, int r) {
        while(r - l > threshold) {
            int x = l, y = r, base = median(arr[l], arr[(l + r) / 2], arr[r]);
            do {
                while(arr[x] < base) x++;
                while(arr[y] > base) y--;
                if(x <= y) {
                    swap(arr[x], arr[y]);
                    x++, y--;
                }
            } while(x <= y);
            __quick_sort_v3(arr, x, r);
            r = y;
        }
        return ;
    }

    void final_insert_sort(vector<int> &arr, int l, int r) {
        int ind = l;
        for(int i = l + 1; i <= r; i++) {
            if(arr[i] < arr[ind]) ind = i;
        }
        while(ind > l) {
            swap(arr[ind], arr[ind - 1]);
            --ind;
        }
        for(int i = l + 2; i <= r; i++) {
            int j = i;
            while(arr[j] < arr[j - 1]) {
                swap(arr[j], arr[j - 1]);
                j--;
            }
        }
        return ;
    }

    void quick_sort_v3(vector<int> &arr, int l, int r) {
        __quick_sort_v3(arr, l, r);
        final_insert_sort(arr, l, r);
        return ;
    }

    vector<int> sortArray(vector<int>& nums) {
        
        quick_sort_v3(nums, 0, nums.size() - 1);

        return nums;
    }
};