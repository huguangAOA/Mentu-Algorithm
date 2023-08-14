class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long fi = 0, ans = 0, n = prices.size();
        for (int i = 0, pre = 0; i < n; i++) {
            if (prices[i] + 1 == pre) fi += 1;
            else fi = 1;
            ans += fi;
            pre = prices[i];
        }
        return ans;
    }
};