class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        stack<int> s;
        vector<int> l(nums.size()), r(nums.size());
        int n = nums.size();
        for (int i = 0; i < n; i++) l[i] = -1, r[i] = n;
        for (int i = 0; i < n; i++) {
            while (s.size() && nums[i] <= nums[s.top()]) {
                r[s.top()] = i;
                s.pop();
            }
            if (s.size()) l[i] = s.top();
            s.push(i);
        }
        vector<long long> sum(n + 1);
        sum[0] = 0;
        for (int i = 0; i < n; i++) sum[i + 1] = sum[i] + nums[i];
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, nums[i] * (sum[r[i]] - sum[l[i] + 1]));
        }
        return ans % (long long)(1e9 + 7);
    }
};