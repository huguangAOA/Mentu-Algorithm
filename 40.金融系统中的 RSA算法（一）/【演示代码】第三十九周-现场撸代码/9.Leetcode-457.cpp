class Solution {
public:
    int getNext(int i, vector<int>& nums) {
        int delta = 1000 * nums.size(), mod = nums.size();
        if (nums[i] < 0) delta = -delta;
        nums[i] += delta;
        return ((i + nums[i]) % mod + mod) % mod;
    }
    bool circularArrayLoop(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (abs(nums[i]) > 1000) continue;
            int p = i, q = i;
            do {
                p = getNext(p, nums);
                q = getNext(getNext(q, nums), nums);
            } while (p != q);
            int a = 0, b = 0, l = 0;
            do {
                if (nums[p] > 0) a += 1;
                else b += 1;
                l += 1;
                p = getNext(p, nums);
            } while (p != q);
            if (l > 1 && (a == 0 || b == 0)) return true;
        }
        return false;
    }
};