class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int n = nums.size(), cnt = 0, a = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] == a) continue;
            cnt += 1;
            if (i + 1 == n) break;
            a = nums[i + 1];
        }
        return n - cnt * 2;
    }
};