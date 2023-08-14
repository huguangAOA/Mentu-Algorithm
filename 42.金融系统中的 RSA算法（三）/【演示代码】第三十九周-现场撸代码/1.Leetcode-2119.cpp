class Solution {
public:
    long long getNum(long long x) {
        long long y = 0;
        while (x) {
            y = y * 10 + x % 10;
            x /= 10;
        }
        return y;
    }
    bool isSameAfterReversals(int num) {
        return getNum(getNum(num)) == num;
    }
};