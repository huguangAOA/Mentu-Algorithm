class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        if(nums.size() == 0) return nums;
        int x = 0, y = nums.size() - 1;
        do {
            while(x < nums.size() && nums[x] % 2) {
                x++;
            }
            while(y >= 0 && nums[y] % 2 == 0) {
                y--;
            }
            if(x <= y) {
                swap(nums[x], nums[y]);
                x++, y--;
            }
        } while(x <= y);
        return nums;
    }
};