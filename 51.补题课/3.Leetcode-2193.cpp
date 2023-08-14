class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int ans = 0, n = s.size();
        for (int i = 0, j = n - 1; i < j; i++, j--) {
            bool single = true;
            for (int k = j; k > i; k--) if (s[i] == s[k]) {
                ans += j - k;
                while (k < j) swap(s[k], s[k + 1]), k += 1;
                single = false;
                break;
            }
            if (single) ans += n / 2 - i, j += 1;
        }
        return ans;
    }
};