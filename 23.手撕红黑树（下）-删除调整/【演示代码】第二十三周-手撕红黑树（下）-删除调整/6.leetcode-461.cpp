class Solution {
public:
    int hammingDistance(int x, int y) {
        x ^= y;
        int cnt = 0;
        while (x) {
            x &= (x - 1);
            cnt += 1;
        }
        return cnt;
    }
};