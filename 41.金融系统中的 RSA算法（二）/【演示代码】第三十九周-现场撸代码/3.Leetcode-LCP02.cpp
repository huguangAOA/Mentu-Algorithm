class Solution {
public:
    vector<int> fraction(vector<int>& cont) {
        int n = 1, m = 0;
        for (int i = cont.size() - 1; i >= 0; i--) {
            swap(n, m);
            n += m * cont[i];
            int r = gcd(n, m);
            n /= r;
            m /= r;
        }
        vector<int> ret(2);
        ret[0] = n, ret[1] = m;
        return ret;
    }
};