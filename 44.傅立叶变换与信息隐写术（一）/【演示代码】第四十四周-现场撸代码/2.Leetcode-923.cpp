class Solution {
public:
    const int mod_num = (int)(1e9 + 7);
    int twoSumMulti(vector<int> &arr, int l, int r, int target) {
        int ans = 0;
        while (l < r) {
            if (arr[l] + arr[r] < target) l += 1;
            else if (arr[l] + arr[r] > target) r -= 1;
            else {
                if (arr[l] == arr[r]) {
                    int n = r - l + 1;
                    ans += n * (n - 1) / 2;
                    ans %= mod_num;
                    break;
                }
                int lcnt = 1, rcnt = 1;
                while (arr[l + 1] == arr[l]) {
                    lcnt += 1;
                    l += 1;
                }
                while (arr[r - 1] == arr[r]) {
                    rcnt += 1;
                    r -= 1;
                }
                ans += lcnt * rcnt;
                ans %= mod_num;
                l += 1, r -= 1;
            }
        }
        return ans;
    }
    int threeSumMulti(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int n = arr.size(), ans = 0;
        for (int i = 0, I = n - 2; i < I; i++) {
            ans += twoSumMulti(arr, i + 1, n - 1, target - arr[i]);
            ans %= mod_num;
        }
        return ans;
    }
};