class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        sort(s.begin(), s.end(), greater<char>());
        string temp, ans = "";
        int i = 0, j;
        while (i < s.size()) {
            temp = "";
            temp += s[i], i += 1;
            while (s[i] == temp[0]) temp += s[i], i += 1;
            j = 0;
            while (temp.size() - j > repeatLimit) {
                ans += temp.substr(j, repeatLimit);
                if (s[i] == 0) return ans;
                ans += s[i], i += 1;
                j += repeatLimit;
            }
            if (j < temp.size()) ans += temp.substr(j, repeatLimit);
        }
        return ans;
    }
};