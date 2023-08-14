class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = 0;
        for (uint32_t i = 0, j = 1, k = (1 << 31); i < 32; i++, j <<= 1, k >>= 1) {
            if (n & j) ret |= k;
        }
        return ret;
    }
};