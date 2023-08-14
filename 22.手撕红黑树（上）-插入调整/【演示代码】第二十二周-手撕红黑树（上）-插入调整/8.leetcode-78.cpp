class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mark;
        for (int i = 0, j = 1; i < 10; i++, j <<= 1) mark[j] = i;
        vector<vector<int>> ret;
        for (int i = 0, I = (1 << n); i < I; i++) {
            vector<int> arr;
            int val = i;
            while (val) {
                arr.push_back(nums[mark[val & (-val)]]);
                val &= (val - 1);
            }
            ret.push_back(arr);
        }
        return ret;
    }
};