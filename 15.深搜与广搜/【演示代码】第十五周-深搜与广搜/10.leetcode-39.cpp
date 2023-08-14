class Solution {
public:
    void dfs(int ind, int target, vector<int> &nums, 
        vector<int> &buff, vector<vector<int>> &ret
    ) {
        if (target < 0) return ;
        if (target == 0) {
            ret.push_back(buff);
            return ;
        }
        if (ind == nums.size()) return ;
        dfs(ind + 1, target, nums, buff, ret);
        buff.push_back(nums[ind]);
        dfs(ind, target - nums[ind], nums, buff, ret);
        buff.pop_back();
        return ;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> buff;
        vector<vector<int>> ret;
        dfs(0, target, candidates, buff, ret);
        return ret;
    }
};