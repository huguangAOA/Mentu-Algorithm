class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        stack<int> s;
        for (int i = 0; i < height.size(); i++) {
            while (s.size() && height[i] > height[s.top()]) {
                int now = s.top();
                s.pop();
                if (s.size() == 0) continue;
                int a = height[i] - height[now];
                int b = height[s.top()] - height[now];
                ans += (i - s.top() - 1) * min(a, b);
            }
            s.push(i);
        }
        return ans;
    }
};