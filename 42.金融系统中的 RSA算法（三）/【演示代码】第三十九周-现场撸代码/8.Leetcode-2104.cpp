class Solution {
public:
    long long getValue(deque<int> &q_min, deque<int> &q_max, vector<int> &nums) {
        auto p = q_min.begin(), q = q_max.begin();
        int pre_pos = -1;
        long long ans = 0;
        while (p != q_min.end()) {
            int pos = min(*p, *q);
            ans += (long long)(pos - pre_pos) * (long long)(nums[*q] - nums[*p]);
            if (*p == pos) p++;
            if (*q == pos) q++;
            pre_pos = pos;
        }
        return ans;
    }
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        deque<int> q_min, q_max;
        for (int i = 0; i < n; i++) {
            while (!q_min.empty() && nums[i] <= nums[q_min.back()]) q_min.pop_back();
            while (!q_max.empty() && nums[i] >= nums[q_max.back()]) q_max.pop_back();
            q_min.push_back(i), q_max.push_back(i);
            ans += getValue(q_min, q_max, nums);
        }
        return ans;
    }
};