class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int i = 0, j = arr.size() - 1;
        while (i < j && arr[i] < arr[i + 1]) ++i;
        while (i < j && arr[j] < arr[j - 1]) --j;
        return i == j && i != 0 && i != arr.size() - 1;
    }
};