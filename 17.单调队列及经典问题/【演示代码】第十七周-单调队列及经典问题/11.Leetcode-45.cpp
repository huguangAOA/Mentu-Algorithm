class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() <= 1) return 0;
        int pre = 1, pos = nums[0], cnt = 1;
        while (pos + 1 < nums.size()) {
            int j = pre;
            for (int i = pre + 1; i <= pos; i++) {
                if (i + nums[i] > j + nums[j]) j = i;
            }
            pre = pos + 1, pos = j + nums[j];
            cnt += 1;
        }
        return cnt;
    }
};