class Solution {
public:
    int longestSubstring(string s, int k) {
        unordered_map<char, int> cnt;
        vector<int> splits;
        for (auto x : s) cnt[x] += 1;
        for (int i = 0; s[i]; ++i) {
            if (cnt[s[i]] < k) splits.push_back(i);
        }
        splits.push_back(s.size());
        if (splits.size() == 1) return s.size();
        int pre = 0, ans = 0;
        for (auto p : splits) {
            int len = p - pre;
            if (len >= k) {
                ans = max(ans, longestSubstring(s.substr(pre, len), k));
            }
            pre = p + 1;
        }
        return ans;
    }
};