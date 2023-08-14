class Solution {
public:
    string smallestSubsequence(string s) {
        string ret;
        unordered_map<char, int> cnt;
        for (auto x : s) cnt[x] += 1;
        unordered_set<char> h;
        for (auto x : s) {
            if (h.find(x) == h.end()) {
                while (ret.size() && cnt[ret.back()] && ret.back() > x) {
                    h.erase(h.find(ret.back()));
                    ret.pop_back();
                }
                h.insert(x);
                ret.push_back(x);
            }
            cnt[x] -= 1;
        }
        return ret;
    }
};