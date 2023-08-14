class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN, pre = 0, sum = 0;
        for (auto x : nums) {
            sum += x;
            ans = max(ans, sum - pre);
            pre = min(pre, sum);
        }
        return ans;
    }
};