class Solution {
public:
    vector<int> nums;
    Solution(vector<int>& nums) : nums(nums) {
        srand(time(0));
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> ret(nums);
        for (int i = 0; i < ret.size(); i++) {
            swap(ret[i], ret[rand() % ret.size()]);
        }
        return ret;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */