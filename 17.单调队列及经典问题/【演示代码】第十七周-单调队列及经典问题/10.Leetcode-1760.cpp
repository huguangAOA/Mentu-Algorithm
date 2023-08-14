class Solution {
public:
    int f(vector<int> &nums, int x) {
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            cnt += nums[i] / x + !!(nums[i] % x) - 1;
        }
        return cnt;
    }
    int bs(vector<int> &nums, int l, int r, int n) {
        if (l == r) return l;
        int mid = (l + r) >> 1;
        if (f(nums, mid) <= n) r = mid;
        else l = mid + 1;
        return bs(nums, l, r, n);
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1, r;
        for (auto x : nums) r = max(r, x);
        return bs(nums, l, r, maxOperations);
    }
};