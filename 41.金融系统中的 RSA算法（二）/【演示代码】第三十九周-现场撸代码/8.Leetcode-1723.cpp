class Solution {
public:
    void dfs(vector<int> &jobs, int ind, vector<int> &slot, int max_num, int &ans) {
        if (ind == jobs.size()) {
            ans = max_num;
            return ;
        }
        int k = slot.size();
        for (int i = 0; i < k; i++) {
            if (slot[i] + jobs[ind] > ans) continue;
            slot[i] += jobs[ind];
            dfs(jobs, ind + 1, slot, max(max_num, slot[i]), ans);
            slot[i] -= jobs[ind];
            if (slot[i] == 0) break;
        }
    }
    int minimumTimeRequired(vector<int>& jobs, int k) {
        vector<int> slot(k, 0);
        int ans = INT_MAX;
        dfs(jobs, 0, slot, 0, ans);
        return ans;
    }
};