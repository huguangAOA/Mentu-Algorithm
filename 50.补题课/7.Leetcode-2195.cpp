class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long sum = 1LL * (1 + k) * k / 2;
        for (long long i = 0, n = nums.size(); i < n && nums[i] <= k; i++) {
            if (i && nums[i] == nums[i - 1]) continue;
            k += 1;
            sum += k - nums[i];
        }
        return sum;
    }
};