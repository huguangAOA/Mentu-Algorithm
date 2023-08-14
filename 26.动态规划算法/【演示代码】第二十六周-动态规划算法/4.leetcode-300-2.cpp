class Solution {
public:
    int binary_search(int *len, int n, int x) {
        int head = 0, tail = n + 1, mid;
        while (head < tail) {
            mid = (head + tail) / 2;
            if (len[mid] >= x) tail = mid;
            else head = mid + 1;
        }
        return head;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int len[n + 1], ans = 0;
        len[0] = INT_MIN;
        for (auto x : nums) {
            int ind = binary_search(len, ans, x);
            len[ind] = x;
            ans = max(ans, ind);
        }
        return ans;
    }
};