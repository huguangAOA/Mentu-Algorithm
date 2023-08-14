class Solution {
public:
    unordered_set<int> pos0, posn;
    void extract(string &s, int i, int j) {
        while (i >= 0 && s[i] == s[j]) {
            if (i == 0) pos0.insert(j);
            if (s[j + 1] == 0) posn.insert(i);
            --i, ++j;
        }
        return ;
    }
    bool check(string &s, int i, int j) {
        while (i >= 0 && s[i] == s[j]) {
            if (pos0.find(i - 1) != pos0.end() 
            && posn.find(j + 1) != posn.end()) return true;
            --i, ++j;
        }
        return false;
    }
    bool checkPartitioning(string s) {
        pos0.clear(), posn.clear();
        for (int i = 0, n = s.size(); i < n; i++) {
            extract(s, i, i);
            extract(s, i, i + 1);
        }
        for (int i = 0, n = s.size(); i < n; i++) {
            if (check(s, i, i)) return true;
            if (check(s, i, i + 1)) return true;
        }
        return false;
    }
};