class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        vector<int> l(nums.size());
        l[0] = INT_MAX;
        for (int i = 1; i < nums.size(); i++) l[i] = min(l[i - 1], nums[i - 1]);
        stack<int> s;
        for (int i = nums.size() - 1; i >= 0; --i) {
            int val = nums[i];
            while (s.size() && nums[i] > s.top()) val = s.top(), s.pop();
            s.push(nums[i]);
            if (l[i] < nums[i] && val < nums[i] && val > l[i]) return true;
        }
        return false;
    }
};