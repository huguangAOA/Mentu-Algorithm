class Solution {
public:
    void extract(string &s, int i, int j, vector<vector<int>> &ind) {
        while (i >= 0 && s[i] == s[j]) {
            ind[j + 1].push_back(i);
            --i, ++j;
        }
        return ;
    }
    int minCut(string s) {
        vector<vector<int>> ind(s.size() + 1);
        for (int i = 0; i < s.size(); i++) {
            extract(s, i, i, ind);
            extract(s, i, i + 1, ind);
        }
        int dp[s.size() + 1];
        dp[0] = 0;
        for (int i = 1, I = s.size(); i <= I; i++) {
            dp[i] = i;
            for (auto j : ind[i]) {
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
        return dp[s.size()] - 1;
    }
};