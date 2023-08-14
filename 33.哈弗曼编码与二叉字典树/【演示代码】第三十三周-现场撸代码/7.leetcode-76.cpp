class Solution {
public:
    string minWindow(string s, string t) {
        int cnt = 0, cnts[128] = {0};
        for (auto x : t) {
            cnts[x] -= 1;
            if (cnts[x] == -1) cnt += 1;
        }
        int ans_len = s.size() + 1, l = 0, r = 0;
        string ans = "";
        while (r <= s.size()) {
            if (cnt) {
                if (r == s.size()) break;
                cnts[s[r]] += 1;
                if (cnts[s[r]] == 0) cnt -= 1;
                r += 1;
            } else {
                cnts[s[l]] -= 1;
                if (cnts[s[l]] == -1) cnt += 1;
                l += 1;
            }
            if (cnt == 0 && r - l < ans_len) {
                ans_len = r - l;
                ans = s.substr(l, r - l);
            }
        }
        return ans;
    }
};