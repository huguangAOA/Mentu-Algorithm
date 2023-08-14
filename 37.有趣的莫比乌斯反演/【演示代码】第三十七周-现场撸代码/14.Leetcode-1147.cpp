class Solution {
public:
    int getResult(string &text, int l, int r) {
        int n = r - l + 1;
        if (n <= 1) return n;
        for (int i = 1, I = n / 2; i <= I; i++) {
            bool flag = true;
            for (int j = l, k = r - i + 1, t = 0; k <= r; j++, k++) {
                if (text[j] == text[k]) continue;
                flag = false;
                break;
            }
            if (flag) return getResult(text, l + i, r - i) + 2;
        }
        return 1;
    }
    int longestDecomposition(string text) {
        return getResult(text, 0, text.size() - 1);
    }
};