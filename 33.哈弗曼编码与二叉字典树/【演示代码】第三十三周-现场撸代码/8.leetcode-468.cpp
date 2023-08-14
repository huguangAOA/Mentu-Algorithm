class Solution {
public:
    bool valid_ipv4(string &s, int l, int r) {
        if (r - l <= 0 || r - l > 3) return false;
        if (r - l > 1 && s[l] == '0') return false;
        int num = 0;
        for (int i = l; i < r; i++) {
            if (s[i] < '0' || s[i] > '9') return false;
            num = num * 10 + s[i] - '0';
        }
        return num < 256;
    }
    
    bool valid_ipv6(string &s, int l, int r) {
        if (r - l <= 0 || r - l > 4) return false;
        for (int i = l; i < r; i++) {
            if (s[i] <= '9' && s[i] >= '0') continue;
            if (s[i] <= 'F' && s[i] >= 'A') continue;
            if (s[i] <= 'f' && s[i] >= 'a') continue;
            return false;
        }
        return true;
    }

    string validIPAddress(string queryIP) {
        int cnt = 0, flag = 0, pre_ind = 0;
        for (int i = 0; i <= queryIP.size(); i++) {
            // ipv4
            if (queryIP[i] == '.' || (flag == 1 && queryIP[i] == 0)) {
                if (flag == 0) flag = 1;
                if (flag != 1 || !valid_ipv4(queryIP, pre_ind, i)) {
                    flag = -1;
                    break;
                }
                cnt += 1;
                pre_ind = i + 1;
            }
            // ipv6
            if (queryIP[i] == ':' || (flag == 2 && queryIP[i] == 0)) {
                if (flag == 0) flag = 2;
                if (flag != 2 || !valid_ipv6(queryIP, pre_ind, i)) {
                    flag = -1;
                    break;
                }
                cnt += 1;
                pre_ind = i + 1;
            }
        }
        if (flag == 1 && cnt == 4) return "IPv4";
        if (flag == 2 && cnt == 8) return "IPv6";
        return "Neither";
    }
};