class Solution {
public:
    bool check(vector<int> &nums, int k, int limit) {
        deque<int> qmin, qmax;
        for (int i = 0; i < nums.size(); i++) {
            while (qmin.size() && nums[i] < nums[qmin.back()]) qmin.pop_back();
            while (qmax.size() && nums[i] > nums[qmax.back()]) qmax.pop_back();
            qmin.push_back(i);
            qmax.push_back(i);
            if (i + 1 < k) continue;
            if (i - qmin.front() == k) qmin.pop_front();
            if (i - qmax.front() == k) qmax.pop_front();
            if (nums[qmax.front()] - nums[qmin.front()] <= limit) return true;
        }
        return false;
    }
    int bs(vector<int> &nums, int l, int r, int limit) {
        if (l == r) return l;
        int mid = (l + r + 1) >> 1;
        if (check(nums, mid, limit)) l = mid;
        else r = mid - 1;
        return bs(nums, l, r, limit);
    }
    int longestSubarray(vector<int>& nums, int limit) {
        return bs(nums, 1, nums.size(), limit);
    }
};