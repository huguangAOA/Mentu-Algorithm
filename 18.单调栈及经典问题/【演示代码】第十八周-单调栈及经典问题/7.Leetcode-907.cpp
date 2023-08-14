class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> s;
        int mod_num = 1e9 + 7;
        long long ans = 0;
        vector<long long> sum(arr.size() + 1);
        sum[0] = 0;
        for (int i = 0; i < arr.size(); i++) {
            while (s.size() && arr[i] <= arr[s.top()]) s.pop();
            int ind = s.size() ? s.top() : -1;
            s.push(i);
            sum[s.size()] = (sum[s.size() - 1] + arr[i] * (i - ind)) % mod_num;
            ans += sum[s.size()];
            ans %= mod_num;
        }
        return ans;
    }
};