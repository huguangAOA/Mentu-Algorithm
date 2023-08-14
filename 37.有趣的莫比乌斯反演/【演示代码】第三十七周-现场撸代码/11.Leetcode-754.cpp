class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int k = floor(sqrt(2 * target));
        while ((1 + k) * k / 2 < target) ++k;
        int delta = (1 + k) * k / 2 - target;
        while (delta & 1) k += 1, delta += k;
        return k;
    }
};