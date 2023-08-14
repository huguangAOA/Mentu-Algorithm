class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        if(k == 0) return ans;
        deque<int> q;

        int idx = 0;
        while(idx < nums.size()) {
            if(!q.empty() && q.front() + k <= idx) {
                q.pop_front();
            }
            while(!q.empty() && nums[q.back()] < nums[idx]) {
                q.pop_back();
            }
            q.push_back(idx);
            idx++;
            if(idx >= k) ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};