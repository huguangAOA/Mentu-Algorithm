class Solution {
public:
    int minSwaps(string s) {
        int ans = 0, l = 0, r = s.size() - 1, lcnt = 0, rcnt = 0;
        lcnt += (s[l] == '[' ? 1 : -1);
        rcnt += (s[r] == ']' ? 1 : -1);
        while (l < r) {
            while (l < r && lcnt >= 0) l += 1, lcnt += (s[l] == '[' ? 1 : -1);
            while (l < r && rcnt >= 0) r -= 1, rcnt += (s[r] == ']' ? 1 : -1);
            if (l >= r) break;
            ans += 1;
            lcnt += 2, rcnt += 2;
        }
        return ans;
    }
};