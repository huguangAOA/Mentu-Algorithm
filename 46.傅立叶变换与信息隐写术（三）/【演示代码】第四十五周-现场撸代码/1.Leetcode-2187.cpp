class Solution {
public:
    long long check(long long t, vector<int>& time) {
        long long sum = 0;
        for (auto x : time) sum += t / x;
        return sum;
    }
    long long binary_search(vector<int>& time, long long l, long long r, long long totalTrips) {
        long long mid;
        while (l < r) {
            mid = (l + r) >> 1;
            if (check(mid, time) < totalTrips) l = mid + 1;
            else r = mid;
        }
        return l;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l = 0, r = 1LL * totalTrips * time[0];
        for (auto x : time) r = min(r, 1LL * totalTrips * x);
        return binary_search(time, l, r, totalTrips);
    }
};