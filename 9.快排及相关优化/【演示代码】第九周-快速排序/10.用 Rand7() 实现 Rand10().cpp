// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int x;
        while (1) {
            x = rand7();
            x = (x - 1) * 7 + rand7(); // 1 - 49
            if (x <= 40) return x % 10 + 1;
            x = (x - 1) *7 + rand7(); // 1 - 63
            if (x <= 60) return x % 10 + 1;
            x = (x - 1) * 7 + rand7(); // 1 - 21
            if (x <= 20) return x % 10 + 1;
        }
        return 0;
    }
};