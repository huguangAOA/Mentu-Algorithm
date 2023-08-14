class Solution {
public:
    int longestValidParentheses(string s) {
        if (s == "") return 0;
        int ans = 0, __dp[s.size() + 5], *dp = __dp + 3;
        memset(__dp, 0, sizeof(__dp));
        dp[0] = 0;
        for (int i = 1; i < s.size(); i++) {
            dp[i] = 0;
            if (s[i] == '(') continue;
            if (s[i - 1] == '(') dp[i] = dp[i - 2] + 2;
            else {
                int j = i - dp[i - 1] - 1;
                if (j < 0 || s[j] == ')') continue;
                dp[i] = dp[i - 1] + 2 + dp[j - 1];
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};