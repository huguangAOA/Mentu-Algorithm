class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        long long sub_max = INT_MIN, add_max = nums[0], a, b, ans = nums[0];
        for (int i = 1; i < n; i++) {
            a = max(sub_max + nums[i], (long long)nums[i]);
            b = add_max - nums[i];
            ans = max(ans, max(a, b));
            sub_max = max(sub_max, b);
            add_max = max(add_max, a);
        }
        return ans;
    }
};