class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string t = "";
        for (int i = 0, n = nums.size(); i < n; i++) {
            t += nums[i][i] == '0' ? '1' : '0';
        }
        return t;
    }
};