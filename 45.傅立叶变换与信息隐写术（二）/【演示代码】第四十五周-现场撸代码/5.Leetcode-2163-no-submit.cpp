class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int m = nums.size(), n = m / 3;
        long long lsum[m], ltotal = 0, rtotal = 0;
        multiset<long long> heap;
        for (int i = 0, sum = 0; i < m; i++) {
            ltotal += nums[i];
            lsum[i] = 0;
            heap.insert(-nums[i]);
            if (heap.size() < n) continue;
            if (heap.size() > n) {
                sum -= *(heap.begin());
                heap.erase(heap.begin());
            }
            lsum[i] = sum;
        }
        heap.clear();
        long long ans = INT_MAX;
        for (int i = m - 1, sum = 0; i >= n; i--) {
            ltotal -= nums[i];
            rtotal += nums[i];
            heap.insert(nums[i]);
            if (heap.size() < n) continue;
            if (heap.size() > n) {
                sum += *(heap.begin());
                heap.erase(heap.begin());
            }
            ans = min(ans, (ltotal - lsum[i - 1]) - (rtotal - sum));
        }
        return ans;
    }
};