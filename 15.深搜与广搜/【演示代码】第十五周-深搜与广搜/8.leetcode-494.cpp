class Solution {
public:
    typedef pair<int, int> PII;
    struct CMP {
        int operator()(const PII &a) const {
            return a.first ^ a.second;
        }
    };
    unordered_map<PII, int, CMP> h;
    int dfs(int i, int target, vector<int> &nums) {
        if (i == nums.size()) {
            return target == 0;
        }
        if (h.find(PII(i, target)) != h.end()) {
            return h[PII(i, target)];
        }
        int ans = 0;
        ans += dfs(i + 1, target - nums[i], nums); // +
        ans += dfs(i + 1, target + nums[i], nums); // -
        h[PII(i, target)] = ans;
        return ans;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        h.clear();
        return dfs(0, target, nums);
    }
};