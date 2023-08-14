class Solution {
public:
    struct Data {
        Data(string s = "", int l = 0)
        : s(s), l(l) {}
        string s;
        int l;
    };
    string getS(string &s, int i, int k) {
        string ret = s;
        switch (k) {
            case 0: ret[i] += 1; break;
            case 1: ret[i] -= 1; break;
        }
        if (ret[i] < '0') ret[i] = '9';
        if (ret[i] > '9') ret[i] = '0';
        return ret;
    }
    int openLock(vector<string>& deadends, string target) {
        queue<Data> q;
        unordered_set<string> h;
        for (auto x : deadends) h.insert(x);
        if (h.find("0000") != h.end()) return -1;
        h.insert("0000");
        q.push(Data("0000", 0));
        while (!q.empty()) {
            Data cur = q.front();
            if (cur.s == target) return cur.l;
            for (int i = 0; i < 4; i++) {
                for (int k = 0; k < 2; k++) {
                    string t = getS(cur.s, i, k);
                    if (h.find(t) != h.end()) continue;
                    h.insert(t);
                    q.push(Data(t, cur.l + 1));
                }
            }
            q.pop();
        }
        return -1;
    }
};