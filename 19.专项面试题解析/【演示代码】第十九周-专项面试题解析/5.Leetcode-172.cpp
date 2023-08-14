class Solution {
public:
    int trailingZeroes(int n) {
        int m = 5, cnt = 0;
        while (n / m) {
            cnt += n / m;
            m *= 5;
        }
        return cnt;
    }
};