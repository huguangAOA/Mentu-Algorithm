class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = -1, ans = 0, n0 = 0;
        while (1) {
            if (n0 <= k) {
                r += 1;
                if (r == nums.size()) break;
                if (nums[r] == 0) n0 += 1;
            } else {
                if (nums[l] == 0) n0 -= 1;
                l += 1;
            }
            if (n0 <= k) ans = max(ans, r - l + 1);
        }
        return ans;
    }
};