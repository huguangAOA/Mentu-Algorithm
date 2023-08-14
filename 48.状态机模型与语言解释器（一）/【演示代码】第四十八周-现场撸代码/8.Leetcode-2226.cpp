class Solution {
public:
    long long check(vector<int> &arr, long long k) {
        if (k == 0) return INT64_MAX;
        long long cnt = 0;
        for (auto x : arr) cnt += x / k;
        return cnt;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long mid, l = 0, r = 0;
        for (auto x : candies) r = max(r, 1LL * x);
        r += 1;
        while (l < r) {
            mid = (l + r) >> 1;
            if (check(candies, mid) >= k) l = mid + 1;
            else r = mid;
        }
        return l - 1;
    }
};