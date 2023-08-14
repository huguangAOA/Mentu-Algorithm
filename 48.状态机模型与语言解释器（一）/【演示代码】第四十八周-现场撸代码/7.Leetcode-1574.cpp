class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size(), q = n - 1, ans = n + 1;
        while (q && arr[q - 1] <= arr[q]) --q;
        if (q == 0) return 0;
        ans = q;
        for (int i = 0; i < n; i++) {
            if (i && arr[i] < arr[i - 1]) break;
            while (q <= i || (q < n && arr[q] < arr[i])) q += 1;
            ans = min(q - i - 1, ans);
        }
        return ans;
    }
};