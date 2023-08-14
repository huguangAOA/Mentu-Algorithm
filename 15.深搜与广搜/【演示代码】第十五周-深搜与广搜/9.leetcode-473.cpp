class Solution {
public:
    bool dfs(int ind, vector<int> &arr, vector<int> &ms) {
        if (ind == -1) return true;
        for (int i = 0; i < 4; i++) {
            if (arr[i] < ms[ind]) continue;
            if (arr[i] == ms[ind] || arr[i] >= ms[ind] + ms[0]) {
                arr[i] -= ms[ind];
                if (dfs(ind - 1, arr, ms)) return true;
                arr[i] += ms[ind];
            }
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        sort(matchsticks.begin(), matchsticks.end());
        vector<int> arr(4);
        int sum = 0;
        for (auto x : matchsticks) sum += x;
        if (sum % 4) return false;
        for (int i = 0; i < 4; i++) arr[i] = sum / 4;
        return dfs(matchsticks.size() - 1, arr, matchsticks);
    }
};