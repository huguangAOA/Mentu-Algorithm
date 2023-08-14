class Solution {
public:
    typedef pair<int, int> PII;
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size(), l = 0, sum = 0;
        vector<PII> ranges;
        for (int r = 0; r < n; r++) {
            sum += arr[r];
            while (sum > target && l <= r) {
                sum -= arr[l];
                l += 1;
            }
            if (sum == target) ranges.push_back(PII(l, r));
        }
        int ans = -1, pre_ind = -1, pre_min = n + 1;
        for (auto x : ranges) {
            while (ranges[pre_ind + 1].second < x.first) {
                pre_ind += 1;
                pre_min = min(pre_min, ranges[pre_ind].second - ranges[pre_ind].first + 1);
            }
            if (pre_ind == -1) continue;
            if (ans == -1 || ans > pre_min + x.second - x.first + 1) {
                ans = pre_min + x.second - x.first + 1;
            }
        }
        return ans;
    }
};