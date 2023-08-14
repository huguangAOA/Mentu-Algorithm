class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = INT_MAX;
        for (int i = k - 1, n = nums.size(); i < n; i++) {
            ans = min(ans, nums[i] - nums[i - k + 1]);
        }
        return ans;
    }
};