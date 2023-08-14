class Solution {
public:
    void delNum(map<long long, int> &h, long long x) {
        h[x] -= 1;
        if (h[x] == 0) h.erase(h.find(x));
        return ;
    }
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        map<long long, int> h;
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) {
                delNum(h, nums[i - k - 1]);
            }
            h[(long long)(nums[i]) - t - 1] += 1;
            h[(long long)(nums[i]) + t + 1] += 1;
            auto iter = h.find((long long)(nums[i]) - t - 1);
            iter++;
            if (iter->first != (long long)(nums[i]) + t + 1) return true;
            delNum(h, (long long)(nums[i]) - t - 1);
            delNum(h, (long long)(nums[i]) + t + 1);
            h[nums[i]] += 1;
        }
        return false;
    }
};