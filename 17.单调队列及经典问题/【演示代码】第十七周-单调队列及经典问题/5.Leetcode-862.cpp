class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> sum(nums.size() + 1);
        sum[0] = 0;
        for (int i = 0; i < nums.size(); i++) sum[i + 1] = sum[i] + nums[i];
        q.push_back(0);
        int pos = -1, ans = -1;
        for (int i = 1; i < sum.size(); i++) {
            while (q.size() && sum[i] - sum[q.front()] >= k) {
                pos = q.front();
                q.pop_front();
            }
            if (pos != -1 && (i - pos < ans || ans == -1)) ans = i - pos;
            while (q.size() && sum[i] < sum[q.back()]) q.pop_back();
            q.push_back(i);
        }
        return ans;
    }
};