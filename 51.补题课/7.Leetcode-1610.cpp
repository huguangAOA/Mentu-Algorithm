class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        double pi = acos(-1), angle_r = 1.0 * angle / 180.0 * pi;
        int n = points.size(), m = 0, ans = 0;
        vector<double> radian(2 * n);
        for (int i = 0; i < n; i++) {
            int dx = points[i][0] - location[0];
            int dy = points[i][1] - location[1];
            if (dx == 0 && dy == 0) {
                ans += 1;
                continue;
            }
            radian[m] = atan2(dy, dx);
            if (radian[m] < 0) radian[m] += 2.0 * pi;
            m += 1;
        }
        sort(radian.begin(), radian.begin() + m);
        for (int i = 0; i < m; i++) radian[i + m] = radian[i] + 2.0 * pi;
        m += m;
        int l = 0, r = -1, max_num = 0;
        while (r < m - 1) {
            if (radian[r + 1] - radian[l] <= angle_r) r += 1;
            else l += 1;
            max_num = max(max_num, r - l + 1);
        }
        return max_num + ans;
    }
};