class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ret(n);
        for (auto x : bookings) {
            ret[x[0] - 1] += x[2];
            if (x[1] < n) ret[x[1]] -= x[2];
        }
        for (int i = 1; i < n; i++) ret[i] += ret[i - 1];
        return ret;
    }
};