class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
        int lmax[n + 1], mmax[n + 1];
        memset(lmax, 0, sizeof(lmax));
        memset(mmax, 0, sizeof(mmax));
        for (int i = n - 1, lsum = 0, msum = 0; i >= 0; i--) {
            lsum += nums[i];
            msum += nums[i];
            if (i + firstLen  < n) lsum -= nums[i + firstLen];
            if (i + secondLen < n) msum -= nums[i + secondLen];
            if (i + firstLen  <= n) lmax[i] = max(lmax[i + 1], lsum);
            if (i + secondLen <= n) mmax[i] = max(mmax[i + 1], msum);
        }
        int ans = 0;
        for (int i = 0, lsum = 0, msum = 0; i < n; i++) {
            lsum += nums[i];
            msum += nums[i];
            if (i >=  firstLen) lsum -= nums[i - firstLen];
            if (i >= secondLen) msum -= nums[i - secondLen];
            ans = max(ans, lsum + mmax[i + 1]);
            ans = max(ans, msum + lmax[i + 1]);
        }
        return ans;
    }
};