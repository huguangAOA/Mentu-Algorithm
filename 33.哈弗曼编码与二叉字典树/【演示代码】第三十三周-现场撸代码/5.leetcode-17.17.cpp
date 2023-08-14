class Solution {
public:
    vector<int> sunday(string &s, string &t) {
        vector<int> ret;
        if (t.size() == 0) return ret;
        int last_ind[128] = {0};
        for (int i = 0; t[i]; i++) last_ind[t[i]] = i + 1;
        int lens = s.size(), lent = t.size(), i = 0;
        while (i + lent <= lens) {
            bool flag = true;
            for (int j = 0; j < lent; j++) {
                if (s[i + j] == t[j]) continue;
                flag = false;
                break;
            }
            if (flag) {
                ret.push_back(i);
                i += 1;
            } else {
                i += lent - last_ind[s[i + lent]] + 1;
            }
        }
        return ret;
    }
    vector<vector<int>> multiSearch(string big, vector<string>& smalls) {
        vector<vector<int>> ret;
        for (auto s : smalls) {
            ret.push_back(sunday(big, s));
        }
        return ret;
    }
};