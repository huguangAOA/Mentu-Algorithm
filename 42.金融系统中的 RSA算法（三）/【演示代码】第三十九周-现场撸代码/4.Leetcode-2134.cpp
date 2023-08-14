class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int ans = INT_MAX, l, r, z_cnt = 0, cnt = 0, n = nums.size();
        for (auto x : nums) if (x == 1) cnt += 1;
        for (int i = 0; i < cnt; i++) if (nums[i] == 0) z_cnt += 1;
        l = 0, r = cnt - 1;
        for (int i = 0; i < n; i++) {
            ans = min(ans, z_cnt);
            if (nums[l] == 0) z_cnt -= 1;
            if (nums[(r + 1) % n] == 0) z_cnt += 1;
            l += 1, r += 1;
        }
        return ans;
    }
};