class Solution {
public:
    bool __isMatch(const char *s, const char *p) {
        if (p[0] == 0) return s[0] == 0;
        if (s[0] == 0) {
            if (p[1] == '*') return __isMatch(s, p + 2);
            else return false;
        }
        bool first_match = s[0] && (s[0] == p[0] || p[0] == '.');
        if (p[1] == '*') {
            return __isMatch(s, p + 2) || (first_match && __isMatch(s + 1, p));
        }
        return first_match && __isMatch(s + 1, p + 1);
    }
    bool isMatch(string s, string p) {
        return __isMatch(s.c_str(), p.c_str());
    }
};