class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int cnt = floor(log2(target)), one_cnt = 0;
        cnt = min(maxDoubles, cnt);
        for (int i = 0; i < cnt; i++) {
            if (target & 1) one_cnt += 1;
            target >>= 1;
        }
        return target - 1 + cnt + one_cnt;
    }
};