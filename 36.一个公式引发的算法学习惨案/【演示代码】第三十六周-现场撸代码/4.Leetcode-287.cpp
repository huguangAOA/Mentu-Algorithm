class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int p = 0, q = 0;
        do {
            p = nums[p];
            q = nums[nums[q]];
        } while (p != q);
        p = 0;
        while (p != q) {
            p = nums[p];
            q = nums[q];
        }
        return p;
    }
};