class Solution {
public:
    void dfs(string &s, int k, int ind, vector<string> &ret) {
        if (ind >= s.size()) return ;
        if (k == 4) {
            int num = 0;
            if (s.size() - ind > 1 && s[ind] == '0') return ;
            for (int i = ind; i < s.size(); i++) {
                num = num * 10 + s[i] - '0';
                if (num > 255) return ;
            }
            ret.push_back(s);
            return ;
        }
        for (int i = ind, num = 0; i < s.size(); i++) {
            num = num * 10 + s[i] - '0';
            if (num > 255) return ;
            if (i - ind >= 1 && s[ind] == '0') return ;
            s.insert(i + 1, ".");
            dfs(s, k + 1, i + 2, ret);
            s.erase(i + 1, 1);
        }
        return ;
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        dfs(s, 1, 0, ret);
        return ret;
    }
};