class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        int n = candiesCount.size(), m = queries.size();
        vector<long long> sum(n); sum[0] = candiesCount[0];
        for (int i = 1; i < n; i++) sum[i] = sum[i - 1] + candiesCount[i];
        vector<bool> ans(m);
        for (int i = 0; i < m; i++) {
            int t = queries[i][0], d = queries[i][1], cap = queries[i][2];
            long long totali = sum[t], totali1 = (t - 1 >= 0 ? sum[t - 1] : 0);
            if (totali < d + 1 || totali1 / cap - 1 >= d) ans[i] = false;
            else ans[i] = true;
        }
        return ans;
    }
};