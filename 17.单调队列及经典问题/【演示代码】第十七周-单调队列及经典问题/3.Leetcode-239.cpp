class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> ret;
        for (int i = 0; i < nums.size(); i++) {
            while (q.size() && nums[q.back()] < nums[i]) q.pop_back();
            q.push_back(i);
            if (i - q.front() == k) q.pop_front();
            if (i + 1 < k) continue;
            ret.push_back(nums[q.front()]);
        }
        return ret;
    }
};