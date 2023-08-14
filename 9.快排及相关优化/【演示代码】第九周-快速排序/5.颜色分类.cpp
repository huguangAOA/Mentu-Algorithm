class Solution {
public:
    void three_partition(vector<int>& arr, int l, int r, int mid) {
        if(l >= r) return ;
        int x = -1, y = r + 1, i = l;
        while(i < y) {
            if(arr[i] == mid) {
                i++;
            } else if(arr[i] < mid) {
                x++;
                swap(arr[x], arr[i]);
                i++;
            } else if(arr[i] > mid) {
                y--;
                swap(arr[y], arr[i]);
            }
        }
    }
    void sortColors(vector<int>& arr) {
        three_partition(arr, 0, arr.size() - 1, 1);
        return ;
    }
};