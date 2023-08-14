class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int n = mat.size(), m = mat[0].size(), sum = 0;
        unordered_set<int> h[2];
        for (auto x : mat[0]) h[0].insert(x), sum = max(sum, x);
        for (int i = 1; i < n; i++) {
            int ind = i % 2, pre_ind = (i - 1) % 2;
            h[ind].clear();
            int max_num = 0;
            for (auto x : mat[i]) max_num = max(x, max_num);
            sum += max_num;
            for (int j = i + 1; j <= sum; j++) {
                for (auto x : mat[i]) {
                    if (h[pre_ind].find(j - x) == h[pre_ind].end()) continue;
                    h[ind].insert(j);
                    break;
                }
            }
        }
        int ans = INT_MAX;
        for (auto x : h[(n - 1) % 2]) ans = min(ans, abs(target - x));
        return ans;
    }
};