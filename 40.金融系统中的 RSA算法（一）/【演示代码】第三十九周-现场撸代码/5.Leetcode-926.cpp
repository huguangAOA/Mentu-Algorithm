class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int ans, n0 = 0, n1 = 0;
        for (auto x : s) if (x == '0') n0 += 1;
        ans = n0;
        for (auto x : s) {
            if (x == '0') n0 -= 1;
            else n1 += 1;
            ans = min(ans, n0 + n1);
        }
        return ans;
    }
};