class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        vector<int> ret(nums.size());
        for (int i = 0; i < nums.size(); i++) ret[i] = -1;
        for (int i = 0; i < nums.size(); i++) {
            while (s.size() && nums[i] > nums[s.top()]) {
                ret[s.top()] = nums[i];
                s.pop();
            }
            s.push(i);
        }
        for (int i = 0; i < nums.size(); i++) {
            while (s.size() && nums[i] > nums[s.top()]) {
                ret[s.top()] = nums[i];
                s.pop();
            }
            s.push(i);
        }
        return ret;
    }
};