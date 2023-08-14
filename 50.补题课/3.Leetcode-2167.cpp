class Solution {
public:
    int minimumTime(string s) {
        int dp1 = 300000, dp2 = 300000;
        for (int i = 0; s[i]; i++) {
            dp2 = min(dp1, dp2) + 1;
            dp1 = min(i, dp1) + 2 * (s[i] == '1');
        }
        return min(min(dp1, dp2), (int)s.size());
    }
};