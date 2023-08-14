class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> a(num1.size()), b(num2.size()), c(a.size() + b.size() - 1);
        for (int i = 0; i < num1.size(); i++) a[a.size() - i - 1] = num1[i] - '0';
        for (int i = 0; i < num2.size(); i++) b[b.size() - i - 1] = num2[i] - '0';
        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < b.size(); j++) {
                c[i + j] += a[i] * b[j];
            }
        }
        for (int i = 0; i < c.size(); i++) {
            if (c[i] < 10) continue;
            if (i + 1 == c.size()) c.push_back(0);
            c[i + 1] += c[i] / 10;
            c[i] %= 10;
        }
        while (c.size() > 1 && c[c.size() - 1] == 0) c.pop_back();
        string ret = "";
        for (int i = c.size() - 1; i >= 0; i--) ret += c[i] + '0';
        return ret;
    }
};