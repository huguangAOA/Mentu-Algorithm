class Solution {
public:
    long long smallestNumber(long long num) {
        if (num == 0) return 0;
        int flag = 1, cnt[10] = {0};
        if (num < 0) flag = -1, num = -num;
        while (num) {
            cnt[num % 10] += 1;
            num /= 10;
        }
        long long ans = 0;
        if (flag == 1) {
            for (int i = 1; i < 10; i++) {
                if (cnt[i] == 0) continue;
                ans = i;
                cnt[i] -= 1;
                break;
            }
        }
        for (int i = (flag == 1 ? 0 : 9), I = 9 - i; i * flag <= I; i += flag) {
            for (int j = 0; j < cnt[i]; j++) {
                ans = ans * 10 + i;
            }
        }
        return ans * flag;
    }
};