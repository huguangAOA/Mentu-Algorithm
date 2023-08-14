class Solution {
public:
    inline int val(int x, vector<int>& mapping) {
        if (x == 0) return mapping[0];
        int base = 1, y = 0;
        while (x) {
            y += base * mapping[x % 10];
            x /= 10;
            base *= 10;
        }
        return y;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        sort(nums.begin(), nums.end(), 
            [&](int x, int y) -> bool {
                return val(x, mapping) < val(y, mapping);
            }
        );
        return nums;
    }
};