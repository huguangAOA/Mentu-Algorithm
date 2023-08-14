class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        deque<int> q;
        q.push_back(0);
        int ans = INT_MIN;
        for (int i = 1; i < points.size(); i++) {
            while (q.size() && points[i][0] - points[q.front()][0] > k) q.pop_front();
            if (q.size()) {
                ans = max(ans, points[i][0] - points[q.front()][0] + points[i][1] + points[q.front()][1]);
            }
            while (q.size() && points[i][1] - points[i][0] > points[q.back()][1] - points[q.back()][0]) q.pop_back();
            q.push_back(i);
        }
        return ans;
    }
};