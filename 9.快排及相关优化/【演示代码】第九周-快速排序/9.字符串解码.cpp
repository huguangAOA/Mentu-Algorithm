class Solution {
public:
    string decodeString(string s) {
        string ret;
        int i = 0;
        while(s[i]) {
            if(s[i] < '0' || s[i] > '9') {
                ret += s[i];
                i++;
            } else {
                int num = 0;
                while(s[i] >= '0' && s[i] <= '9') {
                    num = num * 10 + (s[i++] - '0');
                }
                i++;
                int l = i, r = i, cnt = 1;
                while(cnt) {
                    r += 1;
                    if(s[r] == '[') cnt++;
                    else if(s[r] == ']') cnt--;
                }
                string tmp = decodeString(s.substr(l, r - l));
                while(num--) ret += tmp;
                i = r + 1;
            }
        }
        return ret;
    }
};