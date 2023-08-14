class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int maxq = -k - 2, n = nums.size();
        for (int i = 0; i <= k && i < n; i++) if (nums[i] == key) maxq = i;
        vector<int> ret;
        for (int i = 0; i < n; i++) {
            if (i + k < n && nums[i + k] == key) maxq = i + k;
            if (abs(i - maxq) <= k) ret.push_back(i);
        }
        return ret;
    }
};