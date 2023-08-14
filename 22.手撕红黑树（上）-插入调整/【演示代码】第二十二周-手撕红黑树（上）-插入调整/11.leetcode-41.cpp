class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] != i + 1) {
                if (nums[i] <= 0 || nums[i] > nums.size()) break;
                int ind = nums[i] - 1;
                if (nums[i] == nums[ind]) break;
                swap(nums[i], nums[ind]);
            }
        }
        int ind = 0;
        while (ind < nums.size() && nums[ind] == ind + 1) ++ind;
        return ind + 1;
    }
};