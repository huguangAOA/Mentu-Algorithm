class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int ans = 0, cnt[101] = {0};
        for (auto x : nums) {
            ans += cnt[x];
            cnt[x] += 1;
        }
        return ans;
    }
};