class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        vector<int> l(heights.size()), r(heights.size());
        int n = heights.size();
        for (int i = 0; i < n; i++) l[i] = -1, r[i] = n;
        for (int i = 0; i < n; i++) {
            while (s.size() && heights[i] <= heights[s.top()]) {
                r[s.top()] = i;
                s.pop();
            }
            if (s.size()) l[i] = s.top();
            s.push(i);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, heights[i] * (r[i] - l[i] - 1));
        }
        return ans;
    }
};