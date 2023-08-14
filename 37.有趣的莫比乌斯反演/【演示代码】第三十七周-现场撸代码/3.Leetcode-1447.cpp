class Solution {
public:
    int gcd(int a, int b) {
        if (b) return gcd(b, a % b);
        return a;
    }
    vector<string> simplifiedFractions(int n) {
        vector<string> ret;
        for (int a = 1; a < n; a++) {
            for (int b = a + 1; b <= n; b++) {
                if (gcd(a, b) - 1) continue;
                stringstream ss;
                ss << a << "/" << b;
                ret.push_back(ss.str());
            }
        }
        return ret;
    }
};