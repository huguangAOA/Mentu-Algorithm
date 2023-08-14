class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> h;
        stack<int> s;
        for (auto x : nums2) {
            while (s.size() && x > s.top()) {
                h[s.top()] = x;
                s.pop();
            }
            s.push(x);
        }
        vector<int> ret(nums1.size());
        for (int i = 0; i < nums1.size(); i++) {
            if (h.find(nums1[i]) == h.end()) ret[i] = -1;
            else ret[i] = h[nums1[i]];
        }
        return ret;
    }
};