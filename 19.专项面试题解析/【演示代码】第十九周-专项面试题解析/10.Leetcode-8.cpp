class Solution {
public:
    int myAtoi(string s) {
        int flag = 1, max_pre = INT_MAX / 10, d = INT_MAX % 10, ind = 0, num = 0;
        
        while (s[ind] == ' ') ++ind;
        
        if (s[ind] == '-') flag = -1, ind += 1;
        else if (s[ind] == '+') ind += 1;
        
        for (; s[ind]; ++ind) {
            if (s[ind] < '0' || s[ind] > '9') break;
            if (num > max_pre || (num == max_pre && (s[ind] - '0') > d)) {
                if (flag > 0) return INT_MAX;
                return INT_MIN;
            }
            num = num * 10 + (s[ind] - '0');
        }
        return num * flag;
    }
};