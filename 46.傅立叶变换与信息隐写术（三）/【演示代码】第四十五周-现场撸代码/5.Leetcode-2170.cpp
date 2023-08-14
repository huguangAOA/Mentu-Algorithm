class Solution {
public:
    typedef pair<int, int> PII;
    void getMaxNum(vector<int>& nums, int p, PII &x1, PII &x2) {
        x1.first = x1.second = x2.first = x2.second = 0;
        unordered_map<int, int> cnt;
        for (int i = p, n = nums.size(); i < n; i += 2) cnt[nums[i]] += 1;
        for (auto z : cnt) {
            if (z.second > x1.second) x2 = x1, x1 = z;
            else if (z.second > x2.second) x2 = z;
        }
        return ;
    }
    int minimumOperations(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        PII x1, x2, y1, y2;
        getMaxNum(nums, 0, x1, x2);
        getMaxNum(nums, 1, y1, y2);
        int n = nums.size(), n0 = (n + 1) / 2, n1 = n - n0;
        if (x1.first != y1.first) return (n0 - x1.second) + (n1 - y1.second);
        return min(
            (n0 - x1.second) + (n1 - y2.second),
            (n0 - x2.second) + (n1 - y1.second)
        );
    }
};