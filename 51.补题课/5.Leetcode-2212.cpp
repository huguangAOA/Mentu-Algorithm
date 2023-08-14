class Solution {
public:
    int getPoint(int t, int n, vector<int>& a, vector<int>& b) {
        int k, ans = 0;
        for (int i = 0; i < 12; i++) {
            if ((t & (1 << i)) == 0) b[i] = 0;
            else {
                ans += i;
                if (n < a[i] + 1) return -1;
                b[i] = a[i] + 1;
                n -= a[i] + 1;
                k = i;
            }
        }
        b[k] += n;
        return ans;
    }
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        int max_point = 0;
        vector<int> b(12, 0), temp(12, 0);
        for (int t = 1, T = (1 << 12); t < T; t++) {
            int p = getPoint(t, numArrows, aliceArrows, temp);
            if (p > max_point) {
                max_point = p;
                b = temp;
            }
        }
        return b;
    }
};