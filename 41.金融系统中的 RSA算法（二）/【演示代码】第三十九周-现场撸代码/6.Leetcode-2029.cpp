class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        long long cnt[3] = {0};
        for (auto x : stones) cnt[x % 3] += 1;
        return (cnt[0] % 2 == 0 && cnt[1] * cnt[2] >= 1) || (cnt[0] % 2 == 1 && abs(cnt[1] - cnt[2]) >= 3);
    }
};